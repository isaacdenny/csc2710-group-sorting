#include "sorts.h"
#include "readFileToArray.h"
#include <functional>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <fstream>

using namespace std::chrono;
using namespace std;

SortMeasurement measureSort(string filename, int dataSize, DataSetType dataType, SortType sortType);
void displayProgress(double progress, string setName, SortType sortType, int dataSize);

const string sortNames[8] = {"SELECTION", "INSERTION", "EXCHANGE", "BUBBLE", "MERGE", "QUICK", "HEAP", "HEAP_ALEXA"};

int main()
{
    /*
        1. Define algorithm result data format (what do we need to calculate)
        2. Read datasets into memory
        3. Measure performance and record data into results array
        4. Display results array in multiple formats (console data dump, console graphs?, SDL2 graphs/visuals)
    */
    struct Dataset
    {
        string filename;
        string name;
        int dataSize;
        DataSetType dataSetType;
    };

    Dataset dataSets[NUM_DATASETS] = {
        {"./data/sorted/sorted-1000.txt", "Small Sorted", 1000, SORTED},
        {"./data/sorted/sorted-10000.txt", "Medium Sorted", 10000, SORTED},
        {"./data/sorted/sorted-50000.txt", "Large Sorted", 20000, SORTED},
        {"./data/random/random-1000.txt", "Small Random", 1000, RANDOM},
        {"./data/random/random-10000.txt", "Medium Random", 10000, RANDOM},
        {"./data/random/random-50000.txt", "Large Random", 50000, RANDOM},
        {"./data/random/random-100000.txt", "X Large Random", 100000, RANDOM},
        {"./data/duplicates/duplicates-1000.txt", "Small Duplicates", 1000, DUPLICATES},
        {"./data/duplicates/duplicates-10000.txt", "Medium Duplicates", 10000, DUPLICATES},
        {"./data/duplicates/duplicates-50000.txt", "Large Duplicates", 50000, DUPLICATES},
        {"./data/duplicates/duplicates-100000.txt", "X Large Duplicates", 100000, DUPLICATES},
        {"./data/reverse-sorted/reverse-sorted-1000.txt", "Small Reverse Sorted", 1000, REVERSE},
        {"./data/reverse-sorted/reverse-sorted-10000.txt", "Medium Reverse Sorted", 10000, REVERSE},
        {"./data/reverse-sorted/reverse-sorted-50000.txt", "Large Reverse Sorted", 20000, REVERSE},
        {"./data/professor-1000.txt", "Professor Random", 1000, RANDOM},
    };

    SortMeasurement sms[NUM_DATASETS * NUM_SORTS]; // One measurement for each Dataset/Sort pair
    int measurementCount = 0;
    SortMeasurement sm;

    for (int i = 0; i < NUM_DATASETS; i++)
    {
        for (int j = 0; j < NUM_SORTS; j++)
        {
            displayProgress((double)(i * NUM_SORTS + j) / (NUM_DATASETS * NUM_SORTS), dataSets[i].name, static_cast<SortType>(j), dataSets[i].dataSize);

            sm = measureSort(dataSets[i].filename, dataSets[i].dataSize, dataSets[i].dataSetType, static_cast<SortType>(j));
            sms[measurementCount] = sm;
            measurementCount++;
        }
    }

    for (int i = 0; i < NUM_DATASETS; i++)
    {
        cout << endl
             << setw(40) << dataSets[i].name << " - " << dataSets[i].dataSize << endl
             << endl;
        cout << setw(20) << "Sort Type" << setw(20) << "Time (us)" << setw(20) << "Compares" << setw(20) << "Swaps" << endl;
        cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
        cout << setw(20) << "Selection Sort"
             << setw(20) << sms[i * NUM_SORTS + SELECTION].time
             << setw(20) << sms[i * NUM_SORTS + SELECTION].compares
             << setw(20) << sms[i * NUM_SORTS + SELECTION].swaps << endl;

        cout << setw(20) << "Insertion Sort"
             << setw(20) << sms[i * NUM_SORTS + INSERTION].time
             << setw(20) << sms[i * NUM_SORTS + INSERTION].compares
             << setw(20) << sms[i * NUM_SORTS + INSERTION].swaps << endl;

        cout << setw(20) << "Exchange Sort"
             << setw(20) << sms[i * NUM_SORTS + EXCHANGE].time
             << setw(20) << sms[i * NUM_SORTS + EXCHANGE].compares
             << setw(20) << sms[i * NUM_SORTS + EXCHANGE].swaps << endl;

        cout << setw(20) << "Bubble Sort"
             << setw(20) << sms[i * NUM_SORTS + BUBBLE].time
             << setw(20) << sms[i * NUM_SORTS + BUBBLE].compares
             << setw(20) << sms[i * NUM_SORTS + BUBBLE].swaps << endl;

        cout << setw(20) << "Merge Sort"
             << setw(20) << sms[i * NUM_SORTS + MERGE].time
             << setw(20) << sms[i * NUM_SORTS + MERGE].compares
             << setw(20) << sms[i * NUM_SORTS + MERGE].swaps << endl;

        cout << setw(20) << "Quicksort"
             << setw(20) << sms[i * NUM_SORTS + QUICK].time
             << setw(20) << sms[i * NUM_SORTS + QUICK].compares
             << setw(20) << sms[i * NUM_SORTS + QUICK].swaps << endl;

        cout << setw(20) << "Heap Sort"
             << setw(20) << sms[i * NUM_SORTS + HEAP].time
             << setw(20) << sms[i * NUM_SORTS + HEAP].compares
             << setw(20) << sms[i * NUM_SORTS + HEAP].swaps << endl;

        cout << setw(20) << "Alexa's Heap Sort"
             << setw(20) << sms[i * NUM_SORTS + HEAP_ALEXA].time
             << setw(20) << sms[i * NUM_SORTS + HEAP_ALEXA].compares
             << setw(20) << sms[i * NUM_SORTS + HEAP_ALEXA].swaps << endl;

        cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
    }

    fstream fs;
    fs.open("measurementOutput.csv", fstream::out);

    if (!fs.is_open()) {
        cout << "Error writing output to file";
        return 1;
    }

    fs << "sort_type,data_type,input_size,compares,swaps,time_microsec\r";
    for (int i = 0; i < measurementCount; i++)
    {
        fs << sms[i].sortType << ",";
        fs << sms[i].dataType << ",";
        fs << sms[i].inputSize << ",";
        fs << sms[i].compares << ",";
        fs << sms[i].swaps << ",";
        fs << sms[i].time << "\r";
    }

    fs.close();

    cout << "Measurements written to file";

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
SortMeasurement measureSort(string filename, int dataSize, DataSetType dataType, SortType sortType)
{
    if (dataSize <= 0)
    {
        throw invalid_argument("dataSize must be greater than zero");
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
    case HEAP_ALEXA:
        heap H;
        H.S = data;
        heapsortAlexa(dataSize, H, compCount, swapCount);
        break;
    default:
        throw invalid_argument("dataSize must be greater than zero");
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

void displayProgress(double progress, string setName, SortType sortType, int dataSize)
{
    int barWidth = 80;
    int pos = barWidth * progress;

    cout.flush();
    cout << "Measuring: " << sortNames[sortType] << " on " << setName << " - " << dataSize << " ";

    cout << "[";
    for (int i = 0; i < barWidth; ++i)
    {
        if (i < pos)
            cout << "=";
        else if (i == pos)
            cout << ">";
        else
            cout << " ";
    }
    cout << "] " << int(progress * 100.0) << " %\r";
}