#pragma once

#include <iostream>
#include <time.h>
#include <chrono>
#include <vector>

// Andrew's Part

void Heapify(int Array[], int i, int size, int& steps);
void BuildHeap(int Array[], int size, int& steps);
void HeapSort(int Array[], int size, int& steps);

int LomutoPartition(int Array[], int begin, int end, int& steps);
void QuickSort(int Array[], int begin, int end, int& steps);