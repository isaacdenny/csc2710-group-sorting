/*
Author: Jimi Adegoroye
Date Created: 9/17/2024
Class CSC 2710
Path to file ie: ~/students/jadegorove/JadegoroyeQuicksort.cpp
Compile with: g++ JadegoroyeQuicksort.cpp
Execute with: ./a.out
In this lab, you will implement the Quicksort algorithm as described in the pseudocode from our textbook. 
You will also modify your implementation to track and output the number of times Quicksort and Partition are called, along with their low, high, and partition values. 
You will continue to track the number of comparisons and swaps as we have done previously
*/

#include <cstdlib>
#include <iostream>
#include <chrono>

using namespace std;

void ppartition(int arr[], int low, int high, int& pivotpoint, int& partition_count, int& total_count, int& compare_count, int& swap_count)
{
    int pivotitem = arr[low]; // Choose the first element as the pivot
    int j = low; // Index of the last element in the low partition
    
    partition_count++;  // Increment the partition count
    total_count++; // Increment the total count of calls to Partition
    cout << endl;

    for (int i = low + 1; i<= high; i++)  // Partition the array around the pivot
    {
        compare_count++;  // Increment the comparison count
        if (arr[i] < pivotitem)  // If the current element is less than the pivot
        {
            j++;  // Increment the index of the last element in the low partition
            swap(arr[i], arr[j]);  // Swap the current element with the element at the last element in the low partition
            swap_count++; 
        }
    }
    pivotpoint = j;  // Index of the pivot element
    swap(arr[low], arr[pivotpoint]);  // Swap the pivot element with the first element of the high partition
    swap_count++;  // Increment the swap count
    cout << "Call to Partition returned pivotpoint = " << pivotpoint << endl; // Print the pivot point
} // End of ppartition
 
void quicksort(int arr[], int low, int high, int& quicksort_count, int& partition_count, int& total_count, int& compare_count, int& swap_count)
{
    quicksort_count++; 
    total_count++; // Increment the total count of calls to Quicksort
    cout << endl; 
    cout << "Call " << quicksort_count << " to Quicksort called with Low = " << low << ", High = " << high << endl;  

    if (high > low) // If the list contains more than one element
    {
        int pivotpoint; // Index of the pivot element
        ppartition(arr, low, high, pivotpoint, partition_count, total_count, compare_count, swap_count); // Partition the array
        quicksort(arr, low, pivotpoint - 1, quicksort_count, partition_count, total_count, compare_count, swap_count); // Sort the low partition
        quicksort(arr, pivotpoint + 1, high, quicksort_count, partition_count, total_count, compare_count, swap_count); // Sort the high partition
    }
} // End of quicksort

void printArray(int arr[], int size)  
{
    for (int i = 0; i < size; i++) // Print the array
    {
        cout << arr[i] << " "; // Print the array element
    }
    cout << endl; // Print a new line
} // End of printArray


// Main function
int main() 
{
    int quicksort_count, partition_count, total_count, compare_count, swap_count; // Variables to keep track of counts
    chrono::microseconds duration; // Variable to store the duration of sorting

   // Array 1
    int numbers1[10] = {5, 2, 8, 3, 9, 1, 7, 4, 6, 10}; // Array to be sorted
    quicksort_count = partition_count = total_count = compare_count = swap_count = 0; // Reset the counts
    auto start = chrono::high_resolution_clock::now(); // Start the timer
    quicksort(numbers1, 0, 9, quicksort_count, partition_count, total_count, compare_count, swap_count);
    auto end = chrono::high_resolution_clock::now(); // Stop the timer
    duration = chrono::duration_cast<chrono::microseconds>(end - start); // Calculate the duration
    cout << "Sorted Array: "; // Print the sorted array
    printArray(numbers1, 10); // Print the sorted array
    cout << "Total Comparisons = " << compare_count << endl; // Print the total comparisons
    cout << "Total Swaps = " << swap_count << endl; // Print the total swaps
    cout << "Time taken = " << duration.count() << " microseconds" << endl; 
    cout << "--------------------------------------------------------------------------------" << endl; // Separator

    // Repeat for the rest of the arrays

    // Array 2
    int numbers2[10] = {6, 3, 8, 2, 7, 5, 1, 9, 4, 10};
    quicksort_count = partition_count = total_count = compare_count = swap_count = 0;
    start = chrono::high_resolution_clock::now();
    quicksort(numbers2, 0, 9, quicksort_count, partition_count, total_count, compare_count, swap_count);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Sorted Array: ";
    printArray(numbers2, 10);
    cout << "Total Comparisons = " << compare_count << endl;
    cout << "Total Swaps = " << swap_count << endl;
    cout << "Time taken = " << duration.count() << " microseconds" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    // Array 3
    int numbers3[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    quicksort_count = partition_count = total_count = compare_count = swap_count = 0;
    start = chrono::high_resolution_clock::now();
    quicksort(numbers3, 0, 9, quicksort_count, partition_count, total_count, compare_count, swap_count);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Sorted Array: ";
    printArray(numbers3, 10);
    cout << "Total Comparisons = " << compare_count << endl;
    cout << "Total Swaps = " << swap_count << endl;
    cout << "Time taken = " << duration.count() << " microseconds" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    // Array 4
    int numbers4[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    quicksort_count = partition_count = total_count = compare_count = swap_count = 0; // Reset the counts
    start = chrono::high_resolution_clock::now();
    quicksort(numbers4, 0, 9, quicksort_count, partition_count, total_count, compare_count, swap_count);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Sorted Array: ";
    printArray(numbers4, 10);
    cout << "Total Comparisons = " << compare_count << endl;
    cout << "Total Swaps = " << swap_count << endl;
    cout << "Time taken = " << duration.count() << " microseconds" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    // Array 5
    int numbers5[100] = {14, 84, 25, 54, 86, 59, 73, 70, 76, 39, 78, 91, 94, 28, 51, 66, 36, 100, 15, 64,
                         42, 71, 37, 69, 41, 68, 50, 61, 60, 20, 92, 8, 83, 3, 19, 52, 49, 7, 45, 24,
                         65, 53, 34, 2, 87, 95, 62, 97, 44, 63, 35, 67, 4, 9, 11, 40, 74, 38, 32, 18,
                         21, 48, 43, 81, 99, 79, 26, 55, 29, 85, 1, 75, 57, 10, 88, 33, 93, 22, 16, 56,
                         77, 31, 6, 47, 5, 96, 72, 80, 27, 17, 23, 82, 13, 12, 98, 46, 58, 30, 90, 89};
    quicksort_count = partition_count = total_count = compare_count = swap_count = 0;
    start = chrono::high_resolution_clock::now();
    quicksort(numbers5, 0, 99, quicksort_count, partition_count, total_count, compare_count, swap_count);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Sorted Array: ";
    printArray(numbers5, 100);
    cout << "Total Comparisons = " << compare_count << endl;
    cout << "Total Swaps = " << swap_count << endl;
    cout << "Time taken = " << duration.count() << " microseconds" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    // Array 6
    int numbers6[100] = {59, 72, 25, 24, 92, 64, 65, 82, 12, 44, 80, 69, 68, 30, 35, 58, 26, 79, 75, 3,
                         33, 47, 48, 55, 23, 89, 28, 71, 100, 46, 8, 66, 2, 86, 40, 10, 56, 21, 73, 96,
                         17, 6, 36, 62, 91, 61, 60, 20, 95, 38, 11, 9, 13, 32, 4, 37, 19, 93, 7, 94,
                         99, 70, 52, 42, 77, 97, 67, 98, 74, 90, 34, 84, 16, 22, 88, 18, 81, 43, 76, 50,
                         27, 83, 87, 41, 54, 1, 15, 51, 5, 14, 53, 63, 39, 78, 29, 45, 57, 85, 31, 49};
    quicksort_count = partition_count = total_count = compare_count = swap_count = 0;
    start = chrono::high_resolution_clock::now();
    quicksort(numbers6, 0, 99, quicksort_count, partition_count, total_count, compare_count, swap_count);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Sorted Array: ";
    printArray(numbers6, 100);
    cout << "Total Comparisons = " << compare_count << endl;
    cout << "Total Swaps = " << swap_count << endl;
    cout << "Time taken = " << duration.count() << " microseconds" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    // Array 7
    int numbers7[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                         21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
                         41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
                         61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
                         81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
    quicksort_count = partition_count = total_count = compare_count = swap_count = 0;
    start = chrono::high_resolution_clock::now();
    quicksort(numbers7, 0, 99, quicksort_count, partition_count, total_count, compare_count, swap_count);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Sorted Array: ";
    printArray(numbers7, 100);
    cout << "Total Comparisons = " << compare_count << endl;
    cout << "Total Swaps = " << swap_count << endl;
    cout << "Time taken = " << duration.count() << " microseconds" << endl;
    cout << "-------------------------------------------" << endl;

    // Array 8
    int numbers8[100] = {100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81,
                         80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61,
                         60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41,
                         40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21,
                         20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    quicksort_count = partition_count = total_count = compare_count = swap_count = 0;
    start = chrono::high_resolution_clock::now();
    quicksort(numbers8, 0, 99, quicksort_count, partition_count, total_count, compare_count, swap_count);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Sorted Array: ";
    printArray(numbers8, 100);
    cout << "Total Comparisons = " << compare_count << endl;
    cout << "Total Swaps = " << swap_count << endl;
    cout << "Time taken = " << duration.count() << " microseconds" << endl;
    cout << " " << endl;

    return 0;
}
