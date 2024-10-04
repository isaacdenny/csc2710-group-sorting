#include "sorts.h"

void qspartition(int arr[], int low, int high, int &pivotpoint, uint64_t &compCount, uint64_t &swapCount)
{
    int pivotitem = arr[low]; // Choose the first element as the pivot
    int j = low;              // Index of the last element in the low partition

    for (int i = low + 1; i <= high; i++) // Partition the array around the pivot
    {
        compCount++;            // Increment the comparison count
        if (arr[i] < pivotitem) // If the current element is less than the pivot
        {
            j++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            swapCount++;
        }
    }
    pivotpoint = j; // Index of the pivot element
    int temp = arr[low];
    arr[low] = arr[pivotpoint];
    arr[pivotpoint] = temp;
    swapCount++; // Increment the swap count
}

void quicksort(int arr[], int low, int high, uint64_t &compCount, uint64_t &swapCount)
{
    int pivotpoint; // Index of the pivot element
    if (high > low)
    {
        qspartition(arr, low, high, pivotpoint, compCount, swapCount); // Partition the array
        quicksort(arr, low, pivotpoint - 1, compCount, swapCount);     // Sort the low partition
        quicksort(arr, pivotpoint + 1, high, compCount, swapCount);    // Sort the high partition
    }
}