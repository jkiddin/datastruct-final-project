#include "algorithm.h"

using namespace std;

int main() {
    int n = 100;
    int *randomArray = new int[n];
    int *ascArray = new int[n];
    int *desArray = new int[n];

    //generates the arrays
    int randIndex = 0;
    int temp = 0;
    int j = 0;
    int k = 0;

    for (int i = 1; i < n+1; i++) {
        ascArray[j] = i;
        randomArray[j] = i;
        j++;
    }
    for (int i = n; i >= 0; i--) {
        desArray[k] = i;
        k++;
    }
    for (int i = 0; i < n; i++) {
        randIndex = rand() % n;
        temp = randomArray[i];
        randomArray[i] = randomArray[randIndex];
        randomArray[randIndex] = temp;
    }

    cout << "What sorting algorithm would you like?" << endl;
    cout << "1. Insertion Sort. \n2. Selection Sort. \n3. Bubble Sort. \n4. Merge Sort. \n5. Quick Sort. \n6. Heap Sort." << endl;
    cout << '\n';

    int choice;
    cin >> choice;
    cout << '\n';

    printArrays(ascArray, desArray, randomArray, n);

    cout << "\nSorting..." << endl;
    if (choice == 1) {
        //insertionSort
    }
    else if (choice == 2) {
        //selectionSort
    }
    else if (choice == 3) {
        bubbleSort(ascArray, n);
        bubbleSort(desArray, n);
        bubbleSort(randomArray, n); 
    }
    else if (choice == 4) {
        mergeSort(ascArray, 0, n - 1);
        mergeSort(desArray, 0, n - 1);
        mergeSort(randomArray, 0, n - 1);
    }
    else if (choice == 5) {
        //quickSort
    }
    else if (choice == 6) {
        //heapSort
    }
    else {
        cout << "Not a valid choice. Program exiting. " << endl;
        return 0;
    }
    
    printArrays(ascArray, desArray, randomArray, n);

    delete[] ascArray, desArray, randomArray;

    cout << "\nThe program ran. Congrats or smth" << endl;
    return 0;
}

/*
You need to implement insertion sort, selection sort, bubble sort, merge sort, quicksort, heapsort (increasing order) algorithms and measure the performance of these algorithms in terms of number of steps and CPU running time.  
Task I: 
Implement insertion sort, selection sort, bubble sort, merge sort, quicksort and heapsort to sort the numbers in the increasing order. Write the program to evaluate the performance of your algorithms in two ways: (1) CPU time; (2) total no. of steps.

Input (not enter by the user) include:  
1)	the number of integers to be sorted, n.
2)	generating three instances as follows:
a.	sorted input data set: 1, 2, 3, … n;
b.	reversely sorted input data set: n, n-1, …, 3, 2,1;
c.	random permutation of 1, 2, …, n (random permutation means that each number of 1, 2, …, n appears exactly once in the input data set but with random position. For example, if n=5, then you may have the random permutation 4, 1, 3, 5, 2).

Test your program and do the experiments as follows:
Run the above three generated input data sets for each n (number of integers) = 100, 300, 500, 1000, 3000, 5000, 10000, 50000
Note: 
(1) You may have to repeat the algorithm many times, each time you need to initialize the array. 
(2) Your running time for each sorting algorithm should exclude the time for initialization.  
(3) All measurement should be done in a single run, i.e. you do not need to run once for n=100, another time for n=200, etc
What to turn in:
(1) Well documented source code in C++
(2) Report the number of steps and the CPU running time in a table 
(3) Plot the running time of the algorithm results

Task II: 
For each algorithm, and for each n (number of integers) = 100, 300, 500, 1000, 3000, 5000, 10000, 50000 measure its average running time and average number of steps for 50 randomly generated instances. 
Note the input data should include 50 sets of n numbers with each number generated randomly in the range of [1, n]. Accumulated the total CPU time and the total number of steps for all 50 data sets, and then get the average CPU time and average total number of steps by dividing the total value by 50.  
What to turn in:
(1) Well documented source code in C++
(2) Report the number of steps and the CPU running time in a table 
(3) Plot the running time of the algorithm results
*/