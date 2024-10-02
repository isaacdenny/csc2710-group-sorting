#ifndef SORTS_H
#define SORTS_H

#define NUM_SORTS 8
#define NUM_DATASETS 9

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
    int time = 0, compares = 0, swaps = 0, inputSize = 0;
    SortType sortType = SELECTION;
    DataSetType dataType = SORTED;
};

/*
    All of our sorting function headers can go here so we can include them in the main driver file
*/
void heapify(int arr[], int n, int i, int &compCount, int &swapCount);
void heapsort(int arr[], int n, int &compCount, int &swapCount);

void bubbleSort(int arr[], int n, int &compCount, int &swapCount);

void mergesort(int arr[], int n, int &compCount, int &swapCount);
void merge(int size2, int size3, int array2[], int array3[], int array[], int &compCount, int &swapCount);

void qspartition(int arr[], int low, int high, int &pivotpoint, int &compCount, int &swapCount);
void quicksort(int arr[], int low, int high, int &compCount, int &swapCount);

void exchangeSort(int arr[], int n, int &compCount, int &swapCount);
void selectionSort(int arr[], int n, int &compCount, int &swapCount);
void insertionSort(int arr[], int n, int &compCount, int &swapCount);

// Alexa Heapsort

struct heap
{
    int *S;       // S is indexed from 0 to (n-1)
    int heapsize; // heapsize only takes the values 0 to n
};

void heapsortAlexa(int n, heap &H, int &compare_count, int &swap_count);

#endif
