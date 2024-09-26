#include "sorts.h"

void merge(int size2, int size3, const int array2[],
                                 const int array3[],
                                 int array[]
                                 )
{
    int i, j, k;

    i = 0, j = 0, k = 0;
    while(i < size2 && j < size3)
    {
        if(array2[i] < array3[j])
        {
            array[k] = array2[i];
            i++;
        }

        else
        {
            array[k] = array3[j];
            j++;
        }

        k++;
    }
    if(i > size2)
    {
        while (i < size2)
        {
            array[k] = array2[i];
            i++;
            k++;
        }
    }
            
    else
    {
        array[k] = array3[j];
        j++;
        k++;    
    }

}


void mergesort(int array[], int size)
{
    if (size > 1)
    {
        const int size2 = int(size/2);
        const int size3 = size - size2;
        int *array2 = new int[size2];
        int *array3 = new int[size3];

        for(int k = 0; k <= size2-1; k++)
        {
            array2[k] = array[k];
        }

        for(int j = 0; j <= size3-1; j++)
        {
            array3[j] = array[j+size2];
        }

        mergesort(array2, size2);
        mergesort(array3, size3);
        merge(size2, size3, array2, array3, array);
    }
}


