#include "sorts.h"
#include "visual.h"

int main(int argc, char *argv[])
{
    /*
        1. Define algorithm result data format (what do we need to calculate)
        2. Read datasets into memory
        3. Measure performance and record data into results array
        4. Display results array in multiple formats (console data dump, console graphs?, SDL2 graphs/visuals) 
    */

    int data[4] = {0, 1, 2, 3};
    displayData(data);
    return 0;
}