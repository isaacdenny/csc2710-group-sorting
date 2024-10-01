#include "sorts.h"
#include <iostream>
#include <vector>
#include <chrono>

void insertionSort(int arr[], int n, int& compCount, int& swapCount) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        // Compare the key with each element on the left
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Perform a swap
            j--;
            compCount++; // Count comparisons
            swapCount++;       // Count swaps
        }
        arr[j + 1] = key;  
        compCount++;     // For the final comparison that breaks the while loop
        if (j + 1 != i) {
            swapCount++;       
        }
    }
}
