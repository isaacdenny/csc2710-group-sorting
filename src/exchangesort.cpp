#include "sorts.h"

void exchangeSort(int arr[], int n, int &compCount, int &swapCount)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            compCount++;
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swapCount++;
            }
        }
    }
}
