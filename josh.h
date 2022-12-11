#pragma once

#include <iostream>
#include <time.h>
#include <chrono>
#include <vector>
#include <fstream>

void printArrays(int asc[], int des[], int ran[], int size);

void bubbleSort(int arr[], int n, int& c);

void merge(int arr[], int left, int mid, int right, int& c);
void mergeSort(int arr[], int begin, int end, int& pass);


