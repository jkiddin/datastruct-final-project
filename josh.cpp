#include "josh.h"
#include "hannah.h"

using namespace std;

void printArrays(int asc[], int des[], int ran[], int size) { //only used for testing the sorting algo's.
    cout << "\nThe ascending array currently holds: " << endl;
    for (int i = 0; i < size; i++) {
        cout << " " << asc[i];
    }
    cout << '\n';
    cout << "\nThe descending array currently holds: " << endl;
    for (int i = 0; i < size; i++) {
        cout << " " << des[i];
    }
    cout << '\n';
    cout << "\nThe random array currently holds: " << endl;
    for (int i = 0; i < size; i++) {
        cout << " " << ran[i];
    }
    cout << '\n';
}

void bubbleSort(int arr[], int n, long long int& c) { //c coincides with steps (c for counter)
    int i, j;
    bool swapped;
    c += 3; 
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        c += 3;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
                c += 4; //for loop comparison + increment j = 2 and two statements in if statement = 4
            }
            c++; //if statement
        }
        c++; //initialization of j in for loop
        if (swapped == false) {
            break;
        }
        c++; //if statement
    }
    c++; //initializaiton of i in for loop
}

/*
Time Complexity: O(N^2)
Auxiliary Space: O(1)
*/

void merge(int arr[], int left, int mid, int right, long long int& c) { //c coincides with steps (c for counter)
    int sub1 = mid - left + 1;
    int sub2 = right - mid;

    int* leftArray = new int[sub1];
    int* rightArray = new int[sub2];

    c += 4;

    for (int i = 0; i < sub1; i++) {
        leftArray[i] = arr[left + i];
        c += 3; //comparison, increment, statement
    }
    c++; //i initialization
    for (int j = 0; j < sub2; j++) {
        rightArray[j] = arr[mid + 1 + j];
        c += 3; //comparison, increment, statement
    }
    c++; //j initialization

    int indexS1 = 0;
    int indexS2 = 0;
    int indexArr = left;

    c += 3; //3 statements

    while (indexS1 < sub1 && indexS2 < sub2) {
        if (leftArray[indexS1] <= rightArray[indexS2]) {
            arr[indexArr] = leftArray[indexS1];
            indexS1++;
            c += 2;
        }
        else {
            arr[indexArr] = rightArray[indexS2];
            indexS2++;
            c += 2;
        }
        indexArr++;
        c += 4; //while containing && = 2; if statement = 1 + incrementing index = 1;
    }

    while (indexS1 < sub1) {
        arr[indexArr] = leftArray[indexS1];
        indexS1++;
        indexArr++;
        c += 4;
    }
    while (indexS2 < sub2) {
        arr[indexArr] = rightArray[indexS2];
        indexS2++;
        indexArr++;
        c += 4;
    }
    delete[] leftArray;
    delete[] rightArray;
    c += 2;
}

void mergeSort(int arr[], int begin, int end, long long int& pass, int insertSortNumber) { //pass signifies steps, "passing" through the function calls.
    if (end - begin + 1 <= insertSortNumber) {
        InsertionSort(arr, end + 1, begin, pass);
        return;
    }

    int mid = begin + (end - begin) / 2;
    pass += 5; //if statement, mid initialization, three function calls.
    mergeSort(arr, begin, mid, pass, insertSortNumber);
    mergeSort(arr, mid + 1, end, pass, insertSortNumber);
    merge(arr, begin, mid, end, pass);
    return;
}
 
/*
Time Complexity: O(n log(n))
Auxiliary Space: O(n)
*/