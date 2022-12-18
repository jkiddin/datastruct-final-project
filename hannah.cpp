#include "hannah.h"

void InsertionSort(int A[], int size, int begin, long long int& steps) {
    steps += 2;

    for (int i = begin + 1; i <= size - 1; i++)
    {
        steps += 11;
        int temp = A[i];
        int j = i - 1;
        for (j = i - 1; j >= begin && temp < A[j]; j--)
        {
            steps += 5;
            A[j + 1] = A[j];
        }

        A[j + 1] = temp;
    }
}

void SelectionSort(int A[], int size, long long int& steps) {
    steps += 2;
    for (int i = 1; i <= size - 1; i++)
    {
        steps += 10;

        int smallest = i;
        for (int j = i + 1; j < size; j++)
        {
            steps += 3;
            if (A[j] < A[smallest])
            {
                steps += 1;
                smallest = j;
            }
        }

        //Swap
        int temp = A[i];
        A[i] = A[smallest];
        A[smallest] = temp;
    }
}