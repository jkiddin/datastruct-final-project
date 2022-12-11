#include "Algorithm2.h"

using namespace std;

// Andrew's Part

void BuildHeap(int Array[], int size, int& steps) {

    steps += 4; // initializing i (3 steps) and false comparison i >= 0

    // Left Child: 2i + 1, Right Child: 2i+2
    for (int i = size / 2 - 1; i >= 0; i--) {
        steps += 3;
        // comparing i with 0, decrementing i, and function call
        Heapify(Array, i, size, steps);
    }
}
void Heapify(int Array[], int i, int size, int& steps) {
    int largest = i;
    int temp;

    steps += 9; // 2 initializations + 3 main if statement comparisons (with steps inside)

    if (2 * i + 1 < size) {
        steps += 1; // inner if statement
        if (Array[2 * i + 1] > Array[largest]) {
            largest = 2 * i + 1;
            steps += 3; // multiplication, addition, and assignment
        }
    }
    if (2 * i + 2 < size) {
        steps += 1; // inner if statement
        if (Array[2 * i + 2] > Array[largest]) {
            largest = 2 * i + 2;
            steps += 3; // multiplication, addition, and assignment
        }
    }

    if (largest != i) {
        steps += 5; // 3 assignment + if statement (with steps inside)
        temp = Array[largest];
        Array[largest] = Array[i];
        Array[i] = temp;
        if (largest <= size / 2) {
            steps++;
            Heapify(Array, largest, size, steps);
        }
    }

}

void HeapSort(int Array[], int size, int& steps) {

    int temp;

    steps += 2; // initialization + function call

    BuildHeap(Array, size, steps);

    steps += 2; // intialization + false comparison i > 0

    for (int i = size; i > 0; i--) {
        steps += 9; // two assignments (2 steps each) 3 more assignments, 1 comparison, and 1 function call 
        temp = Array[0];
        Array[0] = Array[i - 1];
        Array[i - 1] = temp;
        size--;
        Heapify(Array, 0, size, steps);
    }
}



int LomutoPartition(int Array[], int begin, int end, int& steps) {

    steps += 4; // intializations of three variables

    int pivot = Array[begin];
    int j = begin + 1;
    int temp;

    steps += 2; // intialization and false comparison i <= end

    for (int i = j; i <= end; i++) {
        steps += 3; // two comparisons and an increment
        if (Array[i] < pivot) {
            steps += 4; // 3 assignments and an increment
            temp = Array[i];
            Array[i] = Array[j];
            Array[j] = temp;
            j++;
        }
    }

    steps += 5; // 2 assignments and 3 operations 

    Array[begin] = Array[j - 1];
    Array[j - 1] = pivot;

    return j - 1;


}

void QuickSort(int Array[], int begin, int end, int& steps) {

    steps += 1; // comparison

    if (begin < end) {
        steps += 4; // 3 function calls and assignment
        int	q = LomutoPartition(Array, begin, end, steps);

        QuickSort(Array, begin, q - 1, steps);
        QuickSort(Array, q + 1, end, steps);
    }
}
