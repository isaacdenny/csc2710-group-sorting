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
    SortMeasurement sm = measureSelection("./data/duplicates/repeated_values-input-1000-float.txt", 1000, DUPLICATES);

    std::cout << sm.inputSize << std::endl;
    std::cout << sm.sortType << std::endl;
    std::cout << sm.compares << std::endl;
    std::cout << sm.swaps << std::endl;
    std::cout << sm.time << std::endl;

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
    readFileToArray(filename, data, dataSize);

    SortMeasurement sm;
    sm.sortType = SELECTION;
    sm.dataType = dataType;
    sm.inputSize = dataSize;

    int compCount = 0, swapCount = 0;
    auto start = high_resolution_clock::now();

    selectionSort(data, dataSize, compCount, swapCount);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();

    sm.compares = compCount;
    sm.swaps = swapCount;
    sm.time = duration;

    delete[] data;

    return sm;
}

SortMeasurement measureMerge(std::string filename, int dataSize, dataSetType dataType)
{
    if (dataSize <= 0)
    {
        throw std::invalid_argument("dataSize must be greater than zero");
    }

    int *data = new int[dataSize];
    readFileToArray(filename, data, dataSize);

    SortMeasurement sm;
    sm.sortType = SELECTION;
    sm.dataType = dataType;
    sm.inputSize = dataSize;

    int compCount = 0, swapCount = 0;
    auto start = high_resolution_clock::now();

    mergesort(data, dataSize, compCount, swapCount);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();

    sm.compares = compCount;
    sm.swaps = swapCount;
    sm.time = duration;

    delete[] data;

    return sm;
}

SortMeasurement measureQuick(std::string filename, int dataSize, dataSetType dataType)
{
    if (dataSize <= 0)
    {
        throw std::invalid_argument("dataSize must be greater than zero");
    }

    int *data = new int[dataSize];
    readFileToArray(filename, data, dataSize);

    SortMeasurement sm;
    sm.sortType = SELECTION;
    sm.dataType = dataType;
    sm.inputSize = dataSize;

    int compCount = 0, swapCount = 0;
    auto start = high_resolution_clock::now();

    quicksort(data, 0, dataSize, compCount, swapCount);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();

    sm.compares = compCount;
    sm.swaps = swapCount;
    sm.time = duration;

    delete[] data;

    return sm;
}


SortMeasurement measureExchange(std::string filename, int dataSize, dataSetType dataType)
{
    if (dataSize <= 0)
    {
        throw std::invalid_argument("dataSize must be greater than zero");
    }

    int *data = new int[dataSize];
    readFileToArray(filename, data, dataSize);

    SortMeasurement sm;
    sm.sortType = SELECTION;
    sm.dataType = dataType;
    sm.inputSize = dataSize;

    int compCount = 0, swapCount = 0;
    auto start = high_resolution_clock::now();

    exchangeSort(data, dataSize, compCount, swapCount);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();

    sm.compares = compCount;
    sm.swaps = swapCount;
    sm.time = duration;

    delete[] data;

    return sm;
}


SortMeasurement measureBubble(std::string filename, int dataSize, dataSetType dataType)
{
    if (dataSize <= 0)
    {
        throw std::invalid_argument("dataSize must be greater than zero");
    }

    int *data = new int[dataSize];
    readFileToArray(filename, data, dataSize);

    SortMeasurement sm;
    sm.sortType = SELECTION;
    sm.dataType = dataType;
    sm.inputSize = dataSize;

    int compCount = 0, swapCount = 0;
    auto start = high_resolution_clock::now();

    bubbleSort(data, dataSize, compCount, swapCount);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();

    sm.compares = compCount;
    sm.swaps = swapCount;
    sm.time = duration;

    delete[] data;

    return sm;
}


SortMeasurement measureInsertion(std::string filename, int dataSize, dataSetType dataType)
{
    if (dataSize <= 0)
    {
        throw std::invalid_argument("dataSize must be greater than zero");
    }

    int *data = new int[dataSize];
    readFileToArray(filename, data, dataSize);

    SortMeasurement sm;
    sm.sortType = SELECTION;
    sm.dataType = dataType;
    sm.inputSize = dataSize;

    int compCount = 0, swapCount = 0;
    auto start = high_resolution_clock::now();

    //insertionSort(data, dataSize, compCount, swapCount);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();

    sm.compares = compCount;
    sm.swaps = swapCount;
    sm.time = duration;

    delete[] data;

    return sm;
}

// measureHeap
// 
// 
// 
// 
// 
