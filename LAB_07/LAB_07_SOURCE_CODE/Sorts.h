/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/31/2017
LAB: 07
FILE NAME: SORTS.H
FILE CONTENTS: HEADER FILE FOR SORTS CLASS
*/

 #ifndef SORTS_H
 #define SORTS_H

 template <typename ItemType>
 class Sorts {
 public:
    // @ pre-condition: expects integer array and int as size of array as parameters
    // @ post-condition: array has been sorted
    // @ throws: none
    static void bubbleSort(ItemType t_arr[], int t_size);

    // @ pre-condition: expects integer array and int as size of array as parameters
    // @ post-condition: array has been sorted
    // @ throws: none
    static void selectionSort(ItemType t_arr[], int t_size);

    // @ pre-condition: expects integer array and int as size of array as parameters
    // @ post-condition: array has been sorted
    // @ throws: none
    static void insertionSort(ItemType t_arr[], int t_size);

    // @ pre-condition: expects integer array, left index, and right index as parameters
    // @ post-condition: array has been sorted
    // @ throws: none
    static void mergeSort(ItemType t_arr[], int t_left_index, int t_right_index);

    // @ pre-condition: expects integer array and size as parameters
    // @ post-condition: array has been sorted
    // @ throws: none
    static void quickSort(ItemType t_arr[], int t_size);

    // @ pre-condition: expects integer array and size as parameters
    // @ post-condition: array has been sorted
    // @ throws: none
    static void quickSortWithMedian(ItemType t_arr[], int t_size);

    // @ pre-condition: expects integer array and size of array as parameters
    // @ post-condition: returns true if array is sorted, false otherwise
    // @ throws: none
    static bool isSorted(ItemType t_arr[], int t_size);

 private:
    // @ pre-condition: expects integer array, left index, middle index, and right index as parameters
    // @ post-condition: subarrays have been merged into single array
    // @ throws: none
    static void merge(ItemType t_arr[], int t_left_index, int t_middle, int t_right_index);

    // @ pre-condition: expects integer array, starting index, ending index, bool of whether to use median
    // @ post-condition: array has been sorted
    // @ throws: none
    static void quickSortRec(ItemType t_arr[], int t_starting, int t_ending, bool t_median);

    // @ pre-condition: expects integer array, starting index, ending index, bool of whether to use median
    // @ post-condition: returns partition index
    // @ throws: none
    static int partition(ItemType t_arr[], int t_starting, int t_ending, bool t_median);

    // @ pre-condition: expects integer array, starting index, and ending index
    // @ post-condition: places median value of array at last index, calls partition method
    // @ throws: none
    static void setMedianPivot(ItemType t_arr[], int t_starting, int t_ending);
 };
 #include "Sorts.hpp"
 #endif