#include "sorts.h"
#include <iostream>
#include <vector>
#include <chrono>

void insertionSort(int arr[], int n, uint64_t &compCount, uint64_t &swapCount)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        int x = arr[i]; // Keytype x
        j = i - 1;
        // Compare and shift elements
        compCount++; // Count comparisons
        while (j >= 0 && arr[j] > x)
        {
            arr[j + 1] = arr[j]; // Shift element to the right
            j--;
            swapCount++; // Count shifts as swaps
        }
        // Place the key (x) in its correct position in the sorted part of the array
        arr[j + 1] = x;
        swapCount++; // Count the placement of the key as a swap
    }
}
