#include <sys/times.h>
#include <chrono>
#include <unistd.h>
//------------------------------------------------------------------------------

template<typename T>
struct WallTime
{
    void
    tic()
    {
	t0 = std::chrono::high_resolution_clock::now();
    }

    T
    toc()
    {
	using namespace std::chrono;

	elapsed = high_resolution_clock::now() - t0;
	return duration<T, seconds::period>(elapsed).count();
    }

    std::chrono::high_resolution_clock::time_point t0;
    std::chrono::high_resolution_clock::duration elapsed;
};


//------------------------------------------------------------------------------

struct time_dat
{
    double time_matrix;
    double time_vector;
    double time_modgauss;
    double time_garner;
    double time_garner_gmp;
    double time_comp;
    double test;
};
