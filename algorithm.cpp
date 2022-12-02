#include "algorithm.h"

using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout <<" "<< arr[i];
}

void bubbleSort(int arr[], int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
                }
            }

        if (swapped == false) {
            break;
        }
    }
}

/*
Time Complexity: O(N^2)
Auxiliary Space: O(1)
*/
 
void merge(int arr[], int left, int mid, int right) {
    int sub1 = mid - left + 1;
    int sub2 = right - mid;
 
    int *leftArray = new int[sub1];
    int *rightArray = new int[sub2];
 
    for (int i = 0; i < sub1; i++) {
        leftArray[i] = arr[left + i];
    }
    for (int j = 0; j < sub2; j++) {
        rightArray[j] = arr[mid + 1 + j];
    }
 
    int indexS1 = 0;
    int indexS2 = 0; 
    int indexArr = left; 
 
    while (indexS1 < sub1 && indexS2 < sub2) {
        if (leftArray[indexS1] <= rightArray[indexS2]) {
            arr[indexArr] = leftArray[indexS1];
            indexS1++;
        }
        else {
            arr[indexArr] = rightArray[indexS2];
            indexS2++;
        }
        indexArr++;
    }

    while (indexS1 < sub1) {
        arr[indexArr] = leftArray[indexS1];
        indexS1++;
        indexArr++;
    }
    while (indexS2 < sub2) {
        arr[indexArr] = rightArray[indexS2];
        indexS2++;
        indexArr++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
void mergeSort(int arr[], int begin, int end)
{
    if (begin >= end) {
        return;
    }

    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

/*
Time Complexity: O(n log(n))
Auxiliary Space: O(n)
*/