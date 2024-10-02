#include "sorts.h"
#include "readFileToArray.h"

#include <iostream>
#include <chrono>

using namespace std::chrono;

SortMeasurement measureSelection(std::string filename, int dataSize, dataSetType dataType);
SortMeasurement measureHeap(std::string filename, int dataSize, dataSetType dataType);
SortMeasurement measureMerge(std::string filename, int dataSize, dataSetType dataType);
SortMeasurement measureQuick(std::string filename, int dataSize, dataSetType dataType);
SortMeasurement measureInsertion(std::string filename, int dataSize, dataSetType dataType);
SortMeasurement measureBubble(std::string filename, int dataSize, dataSetType dataType);
SortMeasurement measureExchange(std::string filename, int dataSize, dataSetType dataType);

int main(int argc, char *argv[])
{
    /*
        1. Define algorithm result data format (what do we need to calculate)
        2. Read datasets into memory
        3. Measure performance and record data into results array
        4. Display results array in multiple formats (console data dump, console graphs?, SDL2 graphs/visuals)
    */

    SortMeasurement sms[63];

    // 1_000 QUICKSORT
    SortMeasurement sm0 = measureQuick("./data/sorted/ordered-input-10000-float.txt", 10000, SORTED);
    SortMeasurement sm1 = measureQuick("./data/random/uniform-input-10000-float.txt", 10000, RANDOM);
    SortMeasurement sm2 = measureQuick("./data/duplicates/repeated_values-input-10000-float.txt", 10000, DUPLICATES);
    SortMeasurement sm3 = measureQuick("./data/reverse-sorted/reverse_ordered-input-10000-float.txt", 10000, REVERSE);

    sms[0] = sm0;
    sms[1] = sm1;
    sms[2] = sm2;
    sms[3] = sm3;

    // 10_000 QUICKSORT
    SortMeasurement sm4 = measureQuick("./data/sorted/ordered-input-10000-float.txt", 10000, SORTED);
    SortMeasurement sm5 = measureQuick("./data/random/uniform-input-10000-float.txt", 10000, RANDOM);
    SortMeasurement sm6 = measureQuick("./data/duplicates/repeated_values-input-10000-float.txt", 10000, DUPLICATES);
    SortMeasurement sm7 = measureQuick("./data/reverse-sorted/reverse_ordered-input-10000-float.txt", 10000, REVERSE);

    sms[4] = sm4;
    sms[5] = sm5;
    sms[6] = sm6;
    sms[7] = sm7;

    // PROFESSORS DATA SET
    SortMeasurement sm8 = measureQuick("./data/test.csv", 1000, RANDOM);

    sms[8] = sm8;

    // 1_000 SELECTION
    SortMeasurement sm9 = measureSelection("./data/sorted/ordered-input-10000-float.txt", 10000, SORTED);
    SortMeasurement sm10 = measureSelection("./data/random/uniform-input-10000-float.txt", 10000, RANDOM);
    SortMeasurement sm11 = measureSelection("./data/duplicates/repeated_values-input-10000-float.txt", 10000, DUPLICATES);
    SortMeasurement sm12 = measureSelection("./data/reverse-sorted/reverse_ordered-input-10000-float.txt", 10000, REVERSE);

    sms[9] = sm9;
    sms[10] = sm10;
    sms[11] = sm11;
    sms[12] = sm12;

    // 10_000 SELECTION
    SortMeasurement sm13 = measureSelection("./data/sorted/ordered-input-10000-float.txt", 10000, SORTED);
    SortMeasurement sm14 = measureSelection("./data/random/uniform-input-10000-float.txt", 10000, RANDOM);
    SortMeasurement sm15 = measureSelection("./data/duplicates/repeated_values-input-10000-float.txt", 10000, DUPLICATES);
    SortMeasurement sm16 = measureSelection("./data/reverse-sorted/reverse_ordered-input-10000-float.txt", 10000, REVERSE);

    sms[13] = sm13;
    sms[14] = sm14;
    sms[15] = sm15;
    sms[16] = sm16;

    // PROFESSORS DATA SET
    SortMeasurement sm17 = measureSelection("./data/test.csv", 1000, RANDOM);

    // 1_000 SELECTION
    SortMeasurement sm18 = measureBubble("./data/sorted/ordered-input-10000-float.txt", 10000, SORTED);
    SortMeasurement sm19 = measureBubble("./data/random/uniform-input-10000-float.txt", 10000, RANDOM);
    SortMeasurement sm20 = measureBubble("./data/duplicates/repeated_values-input-10000-float.txt", 10000, DUPLICATES);
    SortMeasurement sm21 = measureBubble("./data/reverse-sorted/reverse_ordered-input-10000-float.txt", 10000, REVERSE);

    sms[18] = sm18;
    sms[19] = sm19;
    sms[20] = sm20;
    sms[21] = sm21;

    // 10_000 SELECTION
    SortMeasurement sm22 = measureBubble("./data/sorted/ordered-input-10000-float.txt", 10000, SORTED);
    SortMeasurement sm23 = measureBubble("./data/random/uniform-input-10000-float.txt", 10000, RANDOM);
    SortMeasurement sm24 = measureBubble("./data/duplicates/repeated_values-input-10000-float.txt", 10000, DUPLICATES);
    SortMeasurement sm25 = measureBubble("./data/reverse-sorted/reverse_ordered-input-10000-float.txt", 10000, REVERSE);

    sms[22] = sm22;
    sms[23] = sm23;
    sms[24] = sm24;
    sms[25] = sm25;

    // PROFESSORS DATA SET
    SortMeasurement sm26 = measureBubble("./data/test.csv", 1000, RANDOM);

    sms[26] = sm26;

    for (int i = 0; i < 63; i++)
    {
        std::cout << sms[i].inputSize << std::endl;
        std::cout << sms[i].sortType << std::endl;
        std::cout << sms[i].compares << std::endl;
        std::cout << sms[i].swaps << std::endl;
        std::cout << sms[i].time << std::endl;
    }

    /*
        datasize, datatype, compares, swaps, time, sorttype
        10000,SORTED,9014348,28911,9016,SELECTION
        10000,SORTED,9014348,28911,9016,QUICK
        10000,SORTED,9014348,28911,9016,MERGE
        10000,SORTED,9014348,28911,9016,INSERTION
        10000,SORTED,9014348,28911,9016,SELECTION
        10000,SORTED,9014348,28911,9016,SELECTION
        10000,SORTED,9014348,28911,9016,SELECTION
        10000,SORTED,9014348,28911,9016,SELECTION
        10000,SORTED,9014348,28911,9016,SELECTION
    */

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
    sm.sortType = MERGE;
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
    sm.sortType = QUICK;
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
    sm.sortType = EXCHANGE;
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
    sm.sortType = BUBBLE;
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
    sm.sortType = INSERTION;
    sm.dataType = dataType;
    sm.inputSize = dataSize;

    int compCount = 0, swapCount = 0;
    auto start = high_resolution_clock::now();

    insertionSort(data, dataSize, compCount, swapCount);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();

    sm.compares = compCount;
    sm.swaps = swapCount;
    sm.time = duration;

    delete[] data;

    return sm;
}

SortMeasurement measureHeap(std::string filename, int dataSize, dataSetType dataType)
{
    if (dataSize <= 0)
    {
        throw std::invalid_argument("dataSize must be greater than zero");
    }

    int *data = new int[dataSize];
    readFileToArray(filename, data, dataSize);

    SortMeasurement sm;
    sm.sortType = HEAP;
    sm.dataType = dataType;
    sm.inputSize = dataSize;

    int compCount = 0, swapCount = 0;
    auto start = high_resolution_clock::now();

    heapsort(data, dataSize, compCount, swapCount);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();

    sm.compares = compCount;
    sm.swaps = swapCount;
    sm.time = duration;

    delete[] data;

    return sm;
}
