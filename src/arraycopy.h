#ifndef ARRAY_COPY_H
#define ARRAY_COPY_H

#include <string>

int* arraycopy(const std::string& filename, int& arraySize);

#endif


/* THIS IS HOW YOU IMPLEMENT THIS
//Initalize filename, include path for the name.
std::string filename = "ENTER FILENAME HERE";
    int arraySize = 0;
    // Call the function to get the array of numbers from the file
    int* arr = readNumbersFromFile(filename, arraySize); */