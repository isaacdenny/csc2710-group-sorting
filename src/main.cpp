#include "sorts.h"
#include "displayData.h"

int main(int argc, char *argv[])
{
    /*
        1. Define algorithm result data format (what do we need to calculate)
        2. Read datasets into memory
        3. Measure performance and record data into results array
        4. Display results array in multiple formats (console data dump, console graphs?, SDL2 graphs/visuals)
    */
    char *sortNames[7] = {"Selection", "Insertion", "Exchange", "Quick", "Merge", "Heap", "Bubble"};
    SortMeasurement *sm;
    SortMeasurement data[10];

    for (int i = 0; i < 10; i++)
    {
        sm = new SortMeasurement;
        sm->sortName = sortNames[0];
        sm->inputSize = (i + 1) * 20 * 5000;
        sm->time = i * i * 70 * 10;
        sm->compares = 50 * 49 / 2 * 5000;
        sm->swaps = 50 * 49 / 2 + i + 21 * 5000;
        sm->type = RANDOM;

        data[i] = *sm;
    }

    for (int i = 0; i < 10; i++)
    {
        std::cout << "Data " << i << " : " << data[i].inputSize << " " << data[i].time << std::endl;
    }

    displayData(data, 10);
    return 0;
}