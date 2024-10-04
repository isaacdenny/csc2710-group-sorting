#include "sorts.h"

void selectionSort(int arr[], int n, uint64_t &compCount, uint64_t &swapCount)
{
    for (int i = 0; i < n; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < n; j++)
        {
            compCount++;
            if (arr[j] < arr[smallest])
            {
                smallest = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        swapCount++;
    }
}