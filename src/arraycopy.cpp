#include "arraycopy.h"
#include <iostream>
#include <fstream>
#include <vector>

int* arraycopy(const std::string& filename, int& arraySize) {
    std::ifstream inputFile(filename); 
    
    if (!inputFile) {
        std::cerr << "Error Opening File" << std::endl;
        arraySize = 0;
        return nullptr;
    }

    std::vector<int> numbers;
    double num;  //for the floating points

    //reads file
    while (inputFile >> num) {
        numbers.push_back(static_cast<int>(num));  //Turns float into int
    }
    
    //close file
    inputFile.close(); 

    //get the size of the array
    arraySize = numbers.size();

    //dynamically allocated array
    int* arr = new int[arraySize];

    //copy from the vector to the array
    for (int i = 0; i < arraySize; ++i) {
        arr[i] = numbers[i];
    }

    return arr;
}
