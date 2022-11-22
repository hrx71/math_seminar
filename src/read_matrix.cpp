#include <iostream>
#include <fstream>
#include <string>
//#include <funcs.hpp>
#include <vector>

using namespace std;

// source: https://www.c-plusplus.net/forum/topic/248480/c-strings-teilen-und-in-variablen-speichern/11
/**
 * @brief Function to split a string by an integer and save as a vector
 * 
 * @param str input string to be split
 * @param delimiter  
 * @return vector<string> splitted string
 */
vector<string> split( string str, char delimiter )
{
    vector<string> ret;
    while ( true )
    {
        size_t pos = str.find_first_of(delimiter); // find first delimiter 
        string cur = str.substr(0, pos); //substring from beginning to delimiter
        ret.push_back(cur); //save in vector

        // in case pos == npos ( = -1), which meens that no delimiter is left, break while loop
        if ( pos == string::npos ){
            break;
        }
        str = str.substr( pos + 1 ); //overwrite the string with  remaining part of string
    }
    return ret;
}

Matrix read_matrix_from_file(string filepath){
    ifstream input(filepath);

    // source: https://stackoverflow.com/questions/7868936/read-file-line-by-line-using-ifstream-in-c
    vector<vector<string>> lines;
    if (input.is_open()) {
        std::string line;
        while (std::getline(input, line)) {
            lines.push_back( split( line, '\t' ) ); //save splitted string
        }
        input.close();
    }
    Matrix A(lines.size(),lines[0].size(), StorageOrder::RowMajor);
    for (size_t i = 0; i < lines.size(); ++i){
        for (size_t j = 0; j < lines[0].size(); ++j){
            A(i,j) = stoi(lines[i][j]);
            // type conversion string to integer needed here
        }
    }
    return A;
}

