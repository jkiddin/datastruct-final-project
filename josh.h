#pragma once
//josh's part + necessary dependencies. 

#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>

void printArrays(int asc[], int des[], int ran[], int size); //used for testing sorting algo's.

void bubbleSort(int arr[], int n, long long int& c);

void merge(int arr[], int left, int mid, int right, long long int& c);
void mergeSort(int arr[], int begin, int end, long long int& pass, int insertSortNumber);



