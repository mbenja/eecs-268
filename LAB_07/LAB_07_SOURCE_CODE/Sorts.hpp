/*
AUTHOR: BENJAMIN STREIT
KU ID: 2853772
DATE: 10/31/2017
LAB: 07
FILE NAME: SORTS.HPP
FILE CONTENTS: IMPLEMENTATION FILE FOR SORTS CLASS
*/

#include <algorithm>
#include <utility>

template <typename ItemType>
void Sorts<ItemType>::bubbleSort(ItemType t_arr[], int t_size) {
    for (int i = 0; i < (t_size - 1); i++) {
        for (int j = 0; j < (t_size - i - 1); j++) {
            if (t_arr[j] > t_arr[j + 1]) {
                ItemType swap = t_arr[j];
                t_arr[j] = t_arr[j + 1];
                t_arr[j + 1] = swap;
            }
        }
    }
}

template <typename ItemType>
void Sorts<ItemType>::selectionSort(ItemType t_arr[], int t_size) {
    int min_id = 0;

    for (int i = 0; i < t_size - 1; i++) {
        min_id = i;

        for (int j = i + 1; j < t_size; j++) {
            if (t_arr[j] < t_arr[min_id]) {
                min_id = j;
            }
        }

        ItemType swap = t_arr[min_id];
        t_arr[min_id] = t_arr[i];
        t_arr[i] = swap;
    }
}

template <typename ItemType>
void Sorts<ItemType>::insertionSort(ItemType t_arr[], int t_size) {
    int key, j = 0;

    for (int i = 1; i < t_size; i ++) {
        key = t_arr[i];
        j = i - 1;

        // move elements that are greater than key to one index ahead of their current index
        while (j >= 0 && t_arr[j] > key) {
            t_arr[j + 1] = t_arr[j];
            j = j - 1;
        }
        t_arr[j + 1] = key;
    }
}

template <typename ItemType>
void Sorts<ItemType>::mergeSort(ItemType t_arr[], int t_left_index, int t_right_index) {
    if (t_left_index < t_right_index) {
        int middle = t_left_index + (t_right_index - t_left_index) / 2;

        // now sort both halves of initial array
        mergeSort(t_arr, t_left_index, middle);
        mergeSort(t_arr, middle + 1, t_right_index);

        // merge the arrays
        merge(t_arr, t_left_index, middle, t_right_index);
    }
}

template <typename ItemType>
void Sorts<ItemType>::quickSort(ItemType t_arr[], int t_size) {
    quickSortRec(t_arr, 0, t_size, false);
}

template <typename ItemType>
void Sorts<ItemType>::quickSortWithMedian(ItemType t_arr[], int t_size) {
    quickSortRec(t_arr, 0, t_size, true);
}

template <typename ItemType>
void Sorts<ItemType>::merge(ItemType t_arr[], int t_left_index, int t_middle, int t_right_index) {
    int size_1 = t_middle - t_left_index + 1;
    int size_2 = t_right_index - t_middle;

    // creating temp arrays
    int temp_left[size_1], temp_right[size_2];

    // copying data into temp arrays
    for (int i = 0; i < size_1; i++) {
        temp_left[i] = t_arr[t_left_index + i];
    }
    for (int i = 0; i < size_2; i++) {
        temp_right[i] = t_arr[t_middle + 1 + i];
    }

    // merge the subarrays
    // initial indices
    int initial_first = 0;
    int initial_second = 0;
    int initial_merge = t_left_index;

    while (initial_first < size_1 && initial_second < size_2) {
        if (temp_left[initial_first] <= temp_right[initial_second]) {
            t_arr[initial_merge] = temp_left[initial_first];
            initial_first++;
        } else {
            t_arr[initial_merge] = temp_right[initial_second];
            initial_second++;
        }
        initial_merge++;
    }

    // copy any leftover elements in temp_left
    while (initial_first < size_1) {
        t_arr[initial_merge] = temp_left[initial_first];
        initial_first++;
        initial_merge++;
    }

    // copy any leftover elements in temp_right
    while (initial_second < size_2) {
        t_arr[initial_merge] = temp_right[initial_second];
        initial_second++;
        initial_merge++;
    }
}

template <typename ItemType>
void Sorts<ItemType>::quickSortRec(ItemType t_arr[], int t_starting, int t_ending, bool t_median) {
    if (t_starting >= t_ending) {
        return;
    }
    
    int p_index = partition(t_arr, t_starting, t_ending, t_median);

    quickSortRec(t_arr, t_starting, p_index - 1, t_median);
    quickSortRec(t_arr, p_index + 1, t_ending, t_median);
}

template <typename ItemType>
int Sorts<ItemType>::partition(ItemType t_arr[], int t_starting, int t_ending, bool t_median) {
    if (t_median) {
        setMedianPivot(t_arr, t_starting, t_ending);
    } 

    int pivot = t_arr[t_ending];
    
    while (t_starting < t_ending) {
        while (t_arr[t_starting] < pivot) {
            t_starting++;
        }
        while (t_arr[t_ending] > pivot) {
            t_ending--;
        }
        if (t_arr[t_starting] == t_arr[t_ending]) {
            t_starting++;
        } else if (t_starting < t_ending) {
            std::swap(t_arr[t_starting], t_arr[t_ending]);
        }
    }
    return t_ending;
}

template <typename ItemType>
void Sorts<ItemType>::setMedianPivot(ItemType t_arr[], int t_starting, int t_ending) {
    int middle = (t_starting + t_ending) / 2;

    if (t_arr[t_starting] > t_arr[middle]) {
        std::swap(t_arr[middle], t_arr[t_starting]);
    } 
    if (t_arr[t_starting] > t_arr[t_ending]) {
        std::swap(t_arr[middle], t_arr[t_ending]);
    }
    if (t_arr[middle] > t_arr[t_ending]) {
        std::swap(t_arr[t_ending], t_arr[middle]);
    }

    std::swap(t_arr[middle], t_arr[t_starting]);
}

template <typename ItemType>
bool Sorts<ItemType>::isSorted(ItemType t_arr[], int t_size) {
    bool sorted = true;
    ItemType min = t_arr[0];

    for (int i = 0; i < t_size; i++) {
        if (t_arr[i] < min) {
            sorted = false;
        }
    }

    return sorted;
}
