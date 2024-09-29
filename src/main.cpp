#include "sorts.h"
#include "arraycopy.h"

#include <iostream>

int main(int argc, char *argv[])
{
    /*
        1. Define algorithm result data format (what do we need to calculate)
        2. Read datasets into memory
        3. Measure performance and record data into results array
        4. Display results array in multiple formats (console data dump, console graphs?, SDL2 graphs/visuals) 
    */
    // char* sortNames[7] = { "Selection", "Insertion", "Exchange", "Quick", "Merge", "Heap", "Bubble" };
    // SortMeasurement* sm;
    // SortMeasurement data[10];
    
    // for (int i = 0; i < 10; i++) {
    //     sm = new SortMeasurement;
    //     sm->sortName = sortNames[0];
    //     sm->inputSize = (i + 1) * 20;
    //     sm->time = i * 70;
    //     sm->compares = 50 * 49 / 2;
    //     sm->swaps = 50 * 49 / 2 + i + 21;
    //     sm->type = RANDOM;

    //     data[i] = *sm;
    // }

    // for (int i = 0; i < 10; i++) {
    //     std::cout << "Data " << i << " : " << data[i].inputSize << std::endl;
    // }

    // displayData(data, 10);



 /* This is the array copy function, here's how to get it to work.
    int arraysize = 1000; // Change size
    int arr[arraysize]; //Change array name
    std::string filename = "/Users/grahammccabe/csc2710-group-sorting/data/duplicates/repeated_values-input-1000-float.txt"; // File name here

    arraycopy(filename,arr,arraysize); //change array name */


    return 0; 
}