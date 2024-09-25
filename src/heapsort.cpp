#include "sorts.h"

void heapify(int arr[], int n, int i)
{
    // get largest, find branches
    // check if branches are larger, if so, swap and recurse with that index

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[i] < arr[l])
    {
        largest = l;
    }

    if (r < n && arr[largest] < arr[r])
    {
        largest = r;
    }

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    // iterate through array backwards to depth-wise heapify
    // swap the first element with current element and re-heapify

    int i, temp;

    for (i = n - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (i = n; i >= 0; i--)
    {
        temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heapify(arr, i, 0);
    }
}