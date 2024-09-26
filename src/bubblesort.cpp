#include "sorts.h"

void bubbleSort (int arr[], int n) {
    
    bool notSorted = true;
    int i, j, temp;

    while(notSorted) {
        notSorted = false;

        
        for(i = 0; i < n; i++) {
            
            //Sorts through the array and compares left and right elements
            for(j = 0; j < n-i-1; j++) {

                if (arr[j] > arr[j+1]) {
                    //swap elements
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;

                    notSorted = true;
                }
            }

        } 
        n--; //Decrease n since the last element is now in its correct position
    }
}
