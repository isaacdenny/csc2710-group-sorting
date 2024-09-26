#ifndef SORTS_H
#define SORTS_H

enum dataSetType { REVERSE, SORTED, RANDOM, DUPLICATES };

/* Used to measure a sort's performance on a dataset */
struct SortMeasurement {
    char* sortName;
    int time, compares, swaps, inputSize;
    dataSetType type;
};

/*
    All of our sorting function headers can go here so we can include them in the main driver file
*/
void heapify(int arr[], int n, int i);
void heapsort(int arr[], int n);

#endif
