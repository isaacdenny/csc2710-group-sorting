/*
 * Programmer: Alexa Dandrea
 * Date: September 30, 2024
 * Program: Group Project
 * Location: adandrea/si2710/heap.cpp
 *
 * Description:  A program that completes a heapsort given a data set.
 *
 * How to compile: gpp -Wall heap.cpp -o heap
 *
 * How to execute: ./heap
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "sorts.h"

using namespace std;

// Prototypes
void siftdown(heap &H, int i, uint64_t &compare_count, uint64_t &swap_count);
int root(heap &H, uint64_t &compare_count, uint64_t &swap_count);
void removekeys(int n, heap &H, int S[], uint64_t &compare_count, uint64_t &swap_count);
void makeheap(int n, heap &H, uint64_t &compare_count, uint64_t &swap_count);

void siftdown(heap &H, int i, uint64_t &compare_count, uint64_t &swap_count)
{
    int parent, largerChild;
    int siftkey;
    bool spotfound;

    siftkey = H.S[i];
    parent = i;
    spotfound = false;

    while ((2 * parent < H.heapsize) && (!spotfound))
    {
        compare_count++;
        if ((2 * parent < H.heapsize - 1) && (H.S[2 * parent] < H.S[2 * parent + 1]))
        {
            largerChild = 2 * parent + 1;
        }
        else
        {
            largerChild = 2 * parent;
        }

        compare_count++;
        if (siftkey < H.S[largerChild])
        {
            H.S[parent] = H.S[largerChild];
            parent = largerChild;
            swap_count++;
        }
        else
        {
            spotfound = true;
        }
    }
    H.S[parent] = siftkey;
} // end siftdown

int root(heap &H, uint64_t &compare_count, uint64_t &swap_count)
{
    int keyout;

    keyout = H.S[0];
    H.S[0] = H.S[H.heapsize - 1];
    H.heapsize = H.heapsize - 1;
    siftdown(H, 0, compare_count, swap_count);

    return keyout;
} // end root

void removekeys(int n, heap &H, int S[], uint64_t &compare_count, uint64_t &swap_count)
{
    for (int i = n - 1; i >= 0; i--)
    {
        S[i] = root(H, compare_count, swap_count);
    }
} // end removekeys

void makeheap(int n, heap &H, uint64_t &compare_count, uint64_t &swap_count)
{
    H.heapsize = n;

    for (int i = n / 2; i >= 0; i--)
    {
        siftdown(H, i, compare_count, swap_count);
    }
} // end makeheap

void heapsortAlexa(int n, heap &H, uint64_t &compare_count, uint64_t &swap_count)
{
    makeheap(n, H, compare_count, swap_count);
    removekeys(n, H, H.S, compare_count, swap_count);
} // end heapsort