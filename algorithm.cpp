#include "algorithm.h"

using namespace std;

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
 
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout <<" "<< arr[i];
}