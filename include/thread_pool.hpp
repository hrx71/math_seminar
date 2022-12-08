#include <cassert>
#include <condition_variable>
#include <deque>
#include <functional>
#include <future>
#include <mutex>
#include <thread>
#include <utility>
#include <vector>

template<typename T>
struct ThreadPool
{
  public:
    bool finished;
    using Job = std::packaged_task<T()>;
    ThreadPool(unsigned int nof_threads)
      : finished(false)
      , active(0)

      , threads(nof_threads)
    {
	for (auto& t : threads) {
	    t = std::thread([=]() { process_jobs(); });
	}
    }
    ~ThreadPool()
    {
	{
	    std::unique_lock lock(mutex);
	    finished = true;
	}
	cv.notify_all();
	for (auto& t : threads) {
	    t.join();
	}
    }
    template<typename Task>
    std::future<T>
    submit(Task task)
    {
	Job job(task);
	auto result = job.get_future();
	std::unique_lock lock(mutex);
	jobs.emplace_back(std::move(job));
	cv.notify_one();
	return result;
    }

  private:
    unsigned int active;
    std::vector<std::thread> threads;
    std::mutex mutex;
    std::condition_variable cv;
    std::deque<Job> jobs;

    void
    process_jobs()
    {
	for (;;) {
	    Job job;
	    /* fetch job */
	    {
		std::unique_lock lock(mutex);
		while (jobs.empty() && (active > 0 || !finished)) {
		    cv.wait(lock);
		}
		if (jobs.empty() || finished)
		    break;
		job = std::move(jobs.front());
		jobs.pop_front();
		++active;
	    }
	    /* execute job */
	    job();
	    {
		std::unique_lock lock(mutex);
		--active;
	    }
	}
	/* if one thread finishes, all others have to finish as well */
	cv.notify_all();
    }
};

