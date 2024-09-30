#include "sorts.h"
#include "readFileToArray.h"

#include <iostream>
#include <chrono>

using namespace std::chrono;

SortMeasurement measureSelection(std::string filename, int dataSize, dataSetType dataType);

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

/*
    Packages all of our functionality so far into a simple function for selection sort.

    @param filename: the full or local path to the data file
    @param dataSize: length of the data (integer)
    @param dataType: type of data from the enum in sorts.h

    @returns a SortMeasurement object with data about the sort performance
*/
SortMeasurement measureSelection(std::string filename, int dataSize, dataSetType dataType)
{
    if (dataSize <= 0)
    {
        throw std::invalid_argument("dataSize must be greater than zero");
    }

    int *data = new int[dataSize];
    arraycopy(filename, data, dataSize);

    SortMeasurement sm;
    sm.sortType = SELECTION;
    sm.dataType = dataType;
    sm.inputSize = dataSize;

    int compCount = 0, swapCount = 0;
    auto start = high_resolution_clock::now();

    selectionSort(data, dataSize, compCount, swapCount);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();

    for (int i = 0; i < dataSize; i++)
    {
        std::cout << data[i] << " ";
        if (i % 20 == 0)
        {
            std::cout << std::endl;
        }
    }

    sm.compares = compCount;
    sm.swaps = swapCount;
    sm.time = duration;

    delete[] data;

    return sm;
}

// measureHeap
// measureMerge
// measureQuick
// measureExchange
// measureBubble
// measureInsertion