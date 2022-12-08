#include "algorithm.h"

using namespace std;

void printArrays(int asc[], int des[], int ran[], int size) {
    cout << "\nThe ascending array currently holds: " << endl;
    for (int i = 0; i < size; i++) {
        cout <<" "<< asc[i];
    }
    cout << '\n';
    cout << "\nThe descending array currently holds: " << endl;
    for (int i = 0; i < size; i++) {
        cout <<" "<< des[i];
    }
    cout << '\n';
    cout << "\nThe random array currently holds: " << endl;
    for (int i = 0; i < size; i++) {
        cout <<" "<< ran[i];
    }
    cout << '\n';
}

void bubbleSort(int arr[], int n, int &c) {
    c = 0;
    int i, j;
    bool swapped;
    c = c + 3;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        c++;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
                c = c + 2;
                }
            }
        c++;
        if (swapped == false) {
            break;
        }
    }
}

/*
Time Complexity: O(N^2)
Auxiliary Space: O(1)
*/
 
void merge(int arr[], int left, int mid, int right, int &c) {
    int sub1 = mid - left + 1;
    int sub2 = right - mid;
 
    int *leftArray = new int[sub1];
    int *rightArray = new int[sub2];
    
    c = c + 4;
 
    for (int i = 0; i < sub1; i++) {
        leftArray[i] = arr[left + i];
        c++;
    }
    for (int j = 0; j < sub2; j++) {
        rightArray[j] = arr[mid + 1 + j];
        c++;
    }
 
    int indexS1 = 0;
    int indexS2 = 0; 
    int indexArr = left;
    
    c = c + 3;
 
    while (indexS1 < sub1 && indexS2 < sub2) {
        if (leftArray[indexS1] <= rightArray[indexS2]) {
            arr[indexArr] = leftArray[indexS1];
            indexS1++;
            c = c + 3;
        }
        else {
            arr[indexArr] = rightArray[indexS2];
            indexS2++;
            c = c + 3;
        }
        indexArr++;
        c++;
    }

    while (indexS1 < sub1) {
        arr[indexArr] = leftArray[indexS1];
        indexS1++;
        indexArr++;
        c = c + 3;
    }
    while (indexS2 < sub2) {
        arr[indexArr] = rightArray[indexS2];
        indexS2++;
        indexArr++;
        c = c + 3;
    }
    delete[] leftArray;
    delete[] rightArray;
    c = c + 2;
}
 
void mergeSort(int arr[], int begin, int end, int &pass) {
    if (begin >= end) {
        return;
    }
    
    pass = 0;
    
    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid, pass);
    mergeSort(arr, mid + 1, end, pass);
    merge(arr, begin, mid, end, pass);
    pass = pass + 5;
    return;
}

/*
Time Complexity: O(n log(n))
Auxiliary Space: O(n)
*/
