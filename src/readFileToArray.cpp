#include "readFileToArray.h"
#include <iostream>
#include <fstream>

void readFileToArray(const std::string& filename, int arr[], int size) {
    std::ifstream inputFile(filename);  //opens the file
    
    if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    double num;
    int index = 0;

    
    while (inputFile >> num && index < size) {
        arr[index++] = static_cast<int>(num);  //converts num to integer
    }

    inputFile.close();  //close the file
}
