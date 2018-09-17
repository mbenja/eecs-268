/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/31/2017
LAB: 07
FILE NAME: EXECUTIVE.CPP
FILE CONTENTS: IMPLEMENTATION FILE FOR EXECUTIVE CLASS
*/

#include "Executive.h"
#include "Sorts.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cassert>

Executive::Executive(std::string t_sort_name, std::string t_lower_bound, std::string t_upper_bound, std::string t_step, std::string t_output_file, bool t_use_assert) {
    m_size = std::stoi(t_lower_bound);
    int upper_bound = std::stoi(t_upper_bound);
    int step = std::stoi(t_step);
    std::string output = "";
    long double duration = 0.0;

    output += t_sort_name;
    output += '\n';

    // performs requested sort
    while (m_size <= upper_bound) {
        m_arr = new int[m_size];

        // filling array with random values
        for (int i = 0; i < m_size; i++) {
            m_arr[i] = (rand() % 100 + 1);
        }

        if (t_sort_name == "bubble") {
            std::clock_t start;
            start = clock();
            Sorts<int>::bubbleSort(m_arr, m_size);
            duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
        } else if (t_sort_name == "selection") {
            std::clock_t start;
            start = clock();
            Sorts<int>::selectionSort(m_arr, m_size);
            duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
        } else if (t_sort_name == "insertion") {
            std::clock_t start;
            start = clock();
            Sorts<int>::insertionSort(m_arr, m_size);
            duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
        } else if (t_sort_name == "merge") {
            std::clock_t start;
            start = clock();
            Sorts<int>::mergeSort(m_arr, 0, m_size - 1);
            duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
        } else if (t_sort_name == "quickSort") {
            std::clock_t start;
            start = clock();
            Sorts<int>::quickSort(m_arr, m_size);
            duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
        } else if (t_sort_name == "quickSortWithMedian") {
            std::clock_t start;
            start = clock();
            Sorts<int>::quickSortWithMedian(m_arr, m_size);
            duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
        }

        // checks to make sure array is actually sorted if assert statement is used in command line
        if (t_use_assert) {
            assert(Sorts<int>::isSorted(m_arr, m_size));
        }
        
        // appending sort info to string, later to be written to output file
        output += std::to_string(m_size);
        output += ", ";
        output += std::to_string(duration);
        output += "\n";

        m_size += step;
    }

    // writing to file
    writeToFile(t_output_file, output);
}

Executive::~Executive() {
    delete [] m_arr;
}

void Executive::printArray(int t_arr[], int t_size) {
    std::cout << "Printing array..." << std::endl << "[";
    for (int i = 0; i < t_size; i++) {
        std::cout << t_arr[i];

        if (i < (t_size - 1)) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

void Executive::writeToFile(std::string t_output_file, std::string t_output) {
    std::ofstream outFile;

    outFile.open(t_output_file);
    outFile << t_output;
    outFile.close();
}