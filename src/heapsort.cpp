#include "sorts.h"

void heapify(int arr[], int n, int i, int &compCount, int &swapCount)
{
    // get largest, find branches
    // check if branches are larger, if so, swap and recurse with that index

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    compCount++;
    if (l < n && arr[i] < arr[l])
    {
        largest = l;
    }

    compCount++;
    if (r < n && arr[largest] < arr[r])
    {
        largest = r;
    }

    compCount++;
    if (largest != i)
    {
        swapCount++;
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest, compCount, swapCount);
    }
}

void heapsort(int arr[], int n, int &compCount, int &swapCount)
{
    // iterate through array backwards to depth-wise heapify
    // swap the first element with current element and re-heapify

    int i, temp;

    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i, compCount, swapCount);
    }

    for (i = n - 1; i > 0; i--)
    {
        temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heapify(arr, i, 0, compCount, swapCount);
    }
}