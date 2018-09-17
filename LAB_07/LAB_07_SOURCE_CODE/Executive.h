/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/31/2017
LAB: 07
FILE NAME: EXECUTIVE.H
FILE CONTENTS: HEADER FILE FOR EXECUTIVE CLASS
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>

class Executive {
public:
    // @ pre-condition: expects sort guidelines as parameteres, i.e. name, range, step, output file, assert
    // @ post-condition: calls appropriate sort algorithms, exports sort results to output file
    // @ throws: none
    Executive(std::string t_sort_name, std::string t_lower_bound, std::string t_upper_bound, std::string t_step, std::string t_output_file, bool t_use_assert);

    // @ pre-condition: none
    // @ post-condition: all memory allocated to executive class is deallocated
    // @ throws: none
    ~Executive();

    // @ pre-condition: expects integer array and size of array as parameters
    // @ post-condition: array is printed out
    // @ throws: none
    void printArray(int t_arr[], int t_size);

    // @ pre-condition: expects string output file name and output as parameters
    // @ post-condition: m_array is written to file with output file name
    // @ throws: none
    void writeToFile(std::string t_output_file, std::string t_output);

private:
    int* m_arr;
    int m_size;
};
#endif