#include "sorts.h"

/*
Author: Kevin Schoeberle
Mergesort
*/
void merge(int size2, int size3, int array2[],
           int array3[],
           int array[], int &compareCount, int &swapCount)
{
    int i, j, k;
    i = 0, j = 0, k = 0;
    // variable index initializing

    // loops while indexes are less than the sizes of the arrays
    while (i < size2 && j < size3)
    {

        // checks if the value at selected index is lower than the one at the other
        // if it is then swaps OG array with the value of the lowest value between
        // the two compared
        compareCount++;
        if (array2[i] <= array3[j])
        {
            array[k] = array2[i];
            i++;
        }
        else
        {
            array[k] = array3[j];
            swapCount++;
            j++;
        }
        k++;
    }
    // checks if the index is still less than the size at the left array
    if (i < size2)
    {
        while (i < size2)
        {
            array[k] = array2[i];
            i++;
            k++;
        }
    }
    // checks if the index is still less than the size at the right array
    else if (j < size3)
    {
        while (j < size3)
        {
            array[k] = array3[j];
            j++;
            k++;
        }
    }
}

// Mergesort main function
void mergesort(int array[], int size, int &compCount, int &swapCount)
{
    if (size > 1)
    {
        // sizes of arrays initializing divides the OG size by 2 and then floors it then subtracts it from OG size to get size3
        int size2 = size / 2;
        int size3 = size - size2;

        // initializes arrays at runtime
        int *array2 = new int[size2];
        int *array3 = new int[size3];

        // the logic to Mergesort
        mergesort(array2, size2, compCount, swapCount);
        mergesort(array3, size3, compCount, swapCount);
        merge(size2, size3, array2, array3, array, compCount, swapCount);

        delete[] array2;
        delete[] array3;
        // deletes the arrays made preventing memory leaks
    }
}
