#ifndef SORTS_H
#define SORTS_H

#define NUM_SORTS 8
#define NUM_DATASETS 15

#include <string>

enum DataSetType
{
    REVERSE,
    SORTED,
    RANDOM,
    DUPLICATES
};
enum SortType
{
    SELECTION,
    INSERTION,
    EXCHANGE,
    BUBBLE,
    MERGE,
    QUICK,
    HEAP,
    HEAP_ALEXA
};

/* Used to measure a sort's performance on a dataset */
struct SortMeasurement
{
    uint64_t time = 0, compares = 0, swaps = 0, inputSize = 0;
    SortType sortType = SELECTION;
    DataSetType dataType = SORTED;
};

/*
    All of our sorting function headers can go here so we can include them in the main driver file
*/
void heapify(int arr[], int n, int i, uint64_t &compCount, uint64_t &swapCount);
void heapsort(int arr[], int n, uint64_t &compCount, uint64_t &swapCount);

void bubbleSort(int arr[], int n, uint64_t &compCount, uint64_t &swapCount);

void mergesort(int arr[], int n, uint64_t &compCount, uint64_t &swapCount);
void merge(int size2, int size3, int array2[], int array3[], int array[], uint64_t &compCount, uint64_t &swapCount);

void qspartition(int arr[], int low, int high, int &pivotpoint, uint64_t &compCount, uint64_t &swapCount);
void quicksort(int arr[], int low, int high, uint64_t &compCount, uint64_t &swapCount);

void exchangeSort(int arr[], int n, uint64_t &compCount, uint64_t &swapCount);
void selectionSort(int arr[], int n, uint64_t &compCount, uint64_t &swapCount);
void insertionSort(int arr[], int n, uint64_t &compCount, uint64_t &swapCount);

// Alexa Heapsort

struct heap
{
    int *S;       // S is indexed from 0 to (n-1)
    int heapsize; // heapsize only takes the values 0 to n
};

void heapsortAlexa(int n, heap &H, uint64_t &compare_count, uint64_t &swap_count);

#endif
