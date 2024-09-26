#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Selection Sort 
void selectionSort(int n, int myNumbers[100], int& comp_count, int& swap_count) 
{
    comp_count = 0;
    swap_count = 0;

    for (int i = 0; i < n; i++) 
    {
        int smallest = i;
        for (int j = i + 1; j < n; j++) 
        {
            comp_count++;  // Count the comparison
            if (myNumbers[j] < myNumbers[smallest]) 
            {
                smallest = j;
            }
        }
    
            swap(myNumbers[i], myNumbers[smallest]);
            swap_count++;  // Count the swap
    }
}

// Exchange Sort 
void exchangeSort(int n, int myNumbers[100], int& comp_count, int& swap_count) 
{
    comp_count = 0;
    swap_count = 0;

    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            comp_count++;  // Count the comparison
            if (myNumbers[j] < myNumbers[i]) 
            {
                swap(myNumbers[i], myNumbers[j]);
                swap_count++;  //count the swas
            }
        }
    }
}

/*void printArray(const int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}*/

/*int main() {
   // Initialize two arrays with numbers 
   //Array for numbers
    int numbers[100] = 
    {
        14, 84, 25, 54, 86, 59, 73, 70, 76, 39, 78, 91, 94, 28, 51, 66, 36, 100, 15, 64,
        42, 71, 37, 69, 41, 68, 50, 61, 60, 20, 92, 8, 83, 3, 19, 52, 49, 7, 45, 24,
        65, 53, 34, 2, 87, 95, 62, 97, 44, 63, 35, 67, 4, 9, 11, 40, 74, 38, 32, 18,
        21, 48, 43, 81, 99, 79, 26, 55, 29, 85, 1, 75, 57, 10, 88, 33, 93, 22, 16, 56,
        77, 31, 6, 47, 5, 96, 72, 80, 27, 17, 23, 82, 13, 12, 98, 46, 58, 30, 90, 89
    };

    //Array for numbers 2 (you get the gist for the other two arrays for numbers3 ande numbers4)
    int numbers2[100] = 
    {
        59, 72, 25, 24, 92, 64, 65, 82, 12, 44, 80, 69, 68, 30, 35, 58, 26, 79, 75, 3,
        33, 47, 48, 55, 23, 89, 28, 71, 100, 46, 8, 66, 2, 86, 40, 10, 56, 21, 73, 96,
        17, 6, 36, 62, 91, 61, 60, 20, 95, 38, 11, 9, 13, 32, 4, 37, 19, 93, 7, 94,
        99, 70, 52, 42, 77, 97, 67, 98, 74, 90, 34, 84, 16, 22, 88, 18, 81, 43, 76, 50,
        27, 83, 87, 41, 54, 1, 15, 51, 5, 14, 53, 63, 39, 78, 29, 45, 57, 85, 31, 49
    };

    int numbers3[100] = 
    {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 
        61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 
        81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100
    };

    int numbers4[100] = 
    {
        100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 
        80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 
        60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 
        40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 
        20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
    };
    //calculate the size of the number elements 
    //#elements = total size/ size of each item 
    int size = sizeof(numbers) / sizeof(int);

    // Arrays to store copies
    int tempArray[100];
    int comp_count = 0, swap_count = 0;

    // For each array, apply both sorting algorithms (selection and exchange sort) and display results

    // Numbers array
    cout << "\nOriginal array: numbers" << endl;
    printArray(numbers, size);

    memcpy(tempArray, numbers, sizeof(numbers));
    
    // Timer for Selection sort for numbers
    auto start = high_resolution_clock::now();
    selectionSort(size, tempArray, comp_count, swap_count);
    cout << "\nSelection Sort: " << comp_count << " comparisons, " << swap_count << " swaps" << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    
    cout << "The amount of microseconds: " << duration << endl;
    cout << endl;

    memcpy(tempArray, numbers, sizeof(numbers));
    
    //timer for exchange sort number
    start = high_resolution_clock::now();
    exchangeSort(size, tempArray, comp_count, swap_count);
    cout << "Exchange Sort: " << comp_count << " comparisons, " << swap_count << " swaps" << endl;

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count();

    cout << "The amount of microseconds: " << duration << endl;
    cout << endl;

    // Numbers2 array
    cout << "\nOriginal array: numbers2" << endl;
    printArray(numbers2, size);

    memcpy(tempArray, numbers2, sizeof(numbers2));

    // Timer for Selection sort for numbers2
    start = high_resolution_clock::now();
    selectionSort(size, tempArray, comp_count, swap_count);
    cout << "\nSelection Sort: " << comp_count << " comparisons, " << swap_count << " swaps" << endl;

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count();

    cout << "The amount of microseconds: " << duration << endl;
    cout << endl;

    memcpy(tempArray, numbers2, sizeof(numbers2));

    //timer for exchange sort number2
    start = high_resolution_clock::now();
    exchangeSort(size, tempArray, comp_count, swap_count);
    cout << "Exchange Sort: " << comp_count << " comparisons, " << swap_count << " swaps" << endl;

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count();

    cout << "The amount of microseconds: " << duration << endl;
    cout << endl;

    // Numbers3 array
    cout << "\nOriginal array: numbers3" << endl;
    printArray(numbers3, size);

    memcpy(tempArray, numbers3, sizeof(numbers3));

    // Timer for Selection sort for numbers3
    start = high_resolution_clock::now();
    selectionSort(size, tempArray, comp_count, swap_count);
    cout << "\nSelection Sort: " << comp_count << " comparisons, " << swap_count << " swaps" << endl;

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count();

    cout << "The amount of microseconds: " << duration << endl;
    cout << endl;

    memcpy(tempArray, numbers3, sizeof(numbers3));

    //timer for exchange sort number3
    start = high_resolution_clock::now();
    exchangeSort(size, tempArray, comp_count, swap_count);
    cout << "Exchange Sort: " << comp_count << " comparisons, " << swap_count << " swaps" << endl;

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count();

    cout << "The amount of microseconds: " << duration << endl;
    cout << endl;

    // Numbers4 array
    cout << "\nOriginal array: numbers4" << endl;
    printArray(numbers4, size);

    memcpy(tempArray, numbers4, sizeof(numbers4));

    // Timer for Selection sort for numbers4
    start = high_resolution_clock::now();
    selectionSort(size, tempArray, comp_count, swap_count);
    cout << "\nSelection Sort: " << comp_count << " comparisons, " << swap_count << " swaps" << endl;

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count();

    cout << "The amount of microseconds: " << duration << endl;
    cout << endl;

    memcpy(tempArray, numbers4, sizeof(numbers4));

    //timer for exchange sort number4
    start = high_resolution_clock::now();
    exchangeSort(size, tempArray, comp_count, swap_count);
    cout << "Exchange Sort: " << comp_count << " comparisons, " << swap_count << " swaps" << endl;

    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count();

    cout << "The amount of microseconds: " << duration << endl;
    cout << endl;

    return 0;
}*/
