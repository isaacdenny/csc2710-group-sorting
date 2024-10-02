#include "sorts.h"
#include "readFileToArray.h"
#include <functional>
#include <iostream>
#include <chrono>

using namespace std::chrono;

SortMeasurement measureSort(std::string filename, int dataSize, DataSetType dataType, SortType sortType);

int main(int argc, char *argv[])
{
    /*
        1. Define algorithm result data format (what do we need to calculate)
        2. Read datasets into memory
        3. Measure performance and record data into results array
        4. Display results array in multiple formats (console data dump, console graphs?, SDL2 graphs/visuals)
    */
    struct Dataset
    {
        std::string filename;
        int dataSize;
        DataSetType dataSetType;
    };

    Dataset dataSets[9] = {
        {"./data/sorted/sorted-1000.txt", 1000, SORTED},
        {"./data/sorted/sorted-10000.txt", 10000, SORTED},
        {"./data/random/random-1000.txt", 1000, RANDOM},
        {"./data/random/random-10000.txt", 10000, RANDOM},
        {"./data/duplicates/duplicates-1000.txt", 1000, DUPLICATES},
        {"./data/duplicates/duplicates-10000.txt", 10000, DUPLICATES},
        {"./data/reverse-sorted/reverse-sorted-1000.txt", 1000, REVERSE},
        {"./data/reverse-sorted/reverse-sorted-10000.txt", 10000, REVERSE},
        {"./data/professor-1000.txt", 1000, RANDOM},
    };

    SortMeasurement sms[100];
    int measurementCount = 0;
    SortMeasurement sm;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            std::cout << i << "  " << static_cast<SortType>(j) << std::endl;
            sm = measureSort(dataSets[i].filename, dataSets[i].dataSize, dataSets[i].dataSetType, static_cast<SortType>(j));
            sms[measurementCount] = sm;
            measurementCount++;
        }
    }

    for (int i = 0; i < measurementCount; i++)
    {
        std::cout << sms[i].inputSize << " ";
        std::cout << sms[i].sortType << " ";
        std::cout << sms[i].compares << " ";
        std::cout << sms[i].swaps << " ";
        std::cout << sms[i].time << std::endl;
    }

    /*
        Jimi: write the sort measurements from sms array to file line by line like console output.
        
        use measurementOutputSample.csv for reference for what it should look like (comma separated .csv file)

        Also! use the iomanip library to make a nice table in the console with the output
    */ 

    return 0;
}

/*
    Packages all of our functionality so far into a function to measure each sort.

    @param filename: the full or local path to the data file
    @param dataSize: length of the data (integer)
    @param dataType: type of data from the enum in sorts.h
    @param sortFunction: function to meaure
    @param sortType: name of sort algorithm

    @returns a SortMeasurement object with data about the sort performance
*/
SortMeasurement measureSort(std::string filename, int dataSize, DataSetType dataType, SortType sortType)
{
    if (dataSize <= 0)
    {
        throw std::invalid_argument("dataSize must be greater than zero");
    }

    int *data = new int[dataSize];
    readFileToArray(filename, data, dataSize);

    SortMeasurement sm;
    sm.sortType = sortType;
    sm.dataType = dataType;
    sm.inputSize = dataSize;

    int compCount = 0, swapCount = 0;
    auto start = high_resolution_clock::now();

    switch (sortType)
    {
    case QUICK:
        quicksort(data, 0, dataSize - 1, compCount, swapCount);
        break;
    case MERGE:
        mergesort(data, dataSize, compCount, swapCount);
        break;
    case SELECTION:
        selectionSort(data, dataSize, compCount, swapCount);
        break;
    case INSERTION:
        insertionSort(data, dataSize, compCount, swapCount);
        break;
    case EXCHANGE:
        exchangeSort(data, dataSize, compCount, swapCount);
        break;
    case HEAP:
        heapsort(data, dataSize, compCount, swapCount);
        break;
    case BUBBLE:
        bubbleSort(data, dataSize, compCount, swapCount);
        break;
    default:
        throw std::invalid_argument("dataSize must be greater than zero");
        break;
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();

    sm.compares = compCount;
    sm.swaps = swapCount;
    sm.time = duration;

    delete[] data;

    return sm;
}