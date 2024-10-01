#include "sorts.h"

void bubbleSort(int arr[], int n, int &compCount, int &swapCount)
{

    bool notSorted = true;
    int i, j, temp;

    while (notSorted)
    {

        notSorted = false;

        // Sorts through the array and compares left and right elements
        for (i = 0; i < n - 1; i++)
        {
            compCount++;
            if (arr[i] > arr[i + 1])
            {
                // swap elements
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapCount++;

                notSorted = true;
            }
        }
        n--; // decrease n since the last element is now in its correct position
    }
}
