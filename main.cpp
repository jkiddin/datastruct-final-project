#include "algorithm.h"
#include "Algorithm2.h"

using namespace std;
using namespace std::chrono;

void initialize(int randomArray[], int ascArray[], int desArray[]);
void nSetup();

int n;
int counter = 0;

//Works in XCode!
//seperate parts 1 and 2

int main() {
    int choice;
    cout << "Task 1 or 2: ";
    cin >> choice;
    if (choice == 1) {
        while (counter != 4) { //replace with 8 later.
            nSetup();
            int* randomArray = new int[n];
            int* ascArray = new int[n];
            int* desArray = new int[n];

            initialize(randomArray, ascArray, desArray);

            int bubbleSteps;

            cout << "Bubble Sort: " << endl;

            auto start = high_resolution_clock::now();
            bubbleSort(ascArray, n, bubbleSteps);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);

            cout << "Time taken by Bubble Sort for an ascending array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Bubble Sort for an ascending array with " << n << " values: " << bubbleSteps << " steps. " << endl;

            start = high_resolution_clock::now();
            bubbleSort(desArray, n, bubbleSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);

            cout << "\nTime taken by Bubble Sort for a descending array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Bubble Sort for an descending array with " << n << " values: " << bubbleSteps << " steps. " << endl;

            start = high_resolution_clock::now();
            bubbleSort(randomArray, n, bubbleSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);

            cout << "\nTime taken by Bubble Sort for a random array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Bubble Sort for an random array with " << n << " values: " << bubbleSteps << " steps. " << endl;

            cout << '\n';
            initialize(randomArray, ascArray, desArray);

            int mergeSteps;

            cout << "Merge Sort: " << endl;

            start = high_resolution_clock::now();
            mergeSort(ascArray, 0, n - 1, mergeSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);

            cout << "Time taken by Merge Sort for an ascending array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Merge Sort for an ascending array with " << n << " values: " << mergeSteps << " steps. " << endl;

            start = high_resolution_clock::now();
            mergeSort(desArray, 0, n - 1, mergeSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);

            cout << "\nTime taken by Merge Sort for a descending array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Merge Sort for a descending array with " << n << " values: " << mergeSteps << " steps. " << endl;

            start = high_resolution_clock::now();
            mergeSort(randomArray, 0, n - 1, mergeSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);

            cout << "\nTime taken by Merge Sort for a random array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Merge Sort for a random array with " << n << " values: " << mergeSteps << " steps. " << endl;

            //end josh's

            // Andrew's Part

            cout << '\n';
            initialize(randomArray, ascArray, desArray);

            int heapSteps = 0;

            cout << "Heap Sort: " << endl;

            start = high_resolution_clock::now();
            HeapSort(ascArray, n, heapSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);

            cout << "Time taken by Heap Sort for an ascending array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Heap Sort for an ascending array with " << n << " values: " << heapSteps << " steps. " << endl;

            start = high_resolution_clock::now();
            HeapSort(desArray, n, heapSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);

            cout << "\nTime taken by HeapSort for a descending array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Heap Sort for an descending array with " << n << " values: " << heapSteps << " steps. " << endl;

            start = high_resolution_clock::now();
            HeapSort(randomArray, n, heapSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);

            cout << "\nTime taken by Heap Sort for a random array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Heap Sort for an random array with " << n << " values: " << heapSteps << " steps. " << endl;


            cout << '\n';
            initialize(randomArray, ascArray, desArray);

            int quickSteps = 0;

            cout << "Quick Sort: " << endl;

            start = high_resolution_clock::now();
            QuickSort(ascArray, 0, n - 1, quickSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);

            cout << "Time taken by Quick Sort for an ascending array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Quick Sort for an ascending array with " << n << " values: " << quickSteps << " steps. " << endl;

            start = high_resolution_clock::now();
            QuickSort(desArray, 0, n - 1, quickSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);

            cout << "\nTime taken by Quick Sort for a descending array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Quick Sort for a descending array with " << n << " values: " << quickSteps << " steps. " << endl;

            start = high_resolution_clock::now();
            QuickSort(randomArray, 0, n - 1, quickSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);

            cout << "\nTime taken by Quick Sort for a random array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Quick Sort for a random array with " << n << " values: " << quickSteps << " steps. " << endl;


            // End of Andrew's Part


            static_cast<void>(delete[] ascArray), static_cast<void>(desArray),
                static_cast<void>(randomArray);
            //added for mac. will test on windows to ensure compatibility.
            // if u run on windows and it doesn't work, replace with
            // delete[] ascArray, desArray, randomArray;

            cout << "\n\t\tArrays deleted, end of main reached. Resetting...\n" << endl;

            counter++;
        }
        cout << "Program successfully ran. " << endl;
        return 0;
    }
    else if (choice == 2) {
        //part 2
    }
    else {
        cerr << "Not a valid response. Exiting..." << endl;
        return 1;
    }
   
}

void initialize(int randomArray[], int ascArray[], int desArray[]) {
    //generates the arrays
    int randIndex = 0;
    int temp = 0;
    int j = 0;
    int k = 0;

    for (int i = 1; i < n + 1; i++) {
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
}

void nSetup() {
    if (counter == 0) {
        n = 100;
    }
    else if (counter == 1) {
        n = 300;
    }
    else if (counter == 2) {
        n = 500;
    }
    else if (counter == 3) {
        n = 1000;
    }
    else if (counter == 4) {
        n = 3000;
    }
    else if (counter == 5) {
        n = 5000;
    }
    else if (counter == 6) {
        n = 10000;
    }
    else if (counter == 7) {
        n = 50000;
    }
    return;
}

/*
You need to implement insertion sort, selection sort, bubble sort, merge sort, quicksort, heapsort (increasing order) algorithms and measure the performance of these algorithms in terms of number of steps and CPU running time.
Task I:
Implement insertion sort, selection sort, bubble sort, merge sort, quicksort and heapsort to sort the numbers in the increasing order. Write the program to evaluate the performance of your algorithms in two ways: (1) CPU time; (2) total no. of steps.
Input (not enter by the user) include:
1)    the number of integers to be sorted, n.
2)    generating three instances as follows:
a.    sorted input data set: 1, 2, 3, … n;
b.    reversely sorted input data set: n, n-1, …, 3, 2,1;
c.    random permutation of 1, 2, …, n (random permutation means that each number of 1, 2, …, n appears exactly once in the input data set but with random position. For example, if n=5, then you may have the random permutation 4, 1, 3, 5, 2).
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

 !*!*(can generate random data set into a file, load file)*!*!

What to turn in:
(1) Well documented source code in C++
(2) Report the number of steps and the CPU running time in a table
(3) Plot the running time of the algorithm results
*/


//Mac Output (Silicon M1)
/*
 Time taken by Bubble Sort for an ascending array with 100 values: 0 microseconds.
 Time taken by Bubble Sort for a descending array with 100 values: 34 microseconds.
 Time taken by Bubble Sort for a random array with 100 values: 43 microseconds.
 Time taken by Merge Sort for an ascending array with 100 values: 14 microseconds.
 Time taken by Merge Sort for a descending array with 100 values: 10 microseconds.
 Time taken by Merge Sort for a random array with 100 values: 15 microseconds.
         Arrays deleted, end of main reached. Resetting...
 Time taken by Bubble Sort for an ascending array with 300 values: 0 microseconds.
 Time taken by Bubble Sort for a descending array with 300 values: 340 microseconds.
 Time taken by Bubble Sort for a random array with 300 values: 296 microseconds.
 Time taken by Merge Sort for an ascending array with 300 values: 34 microseconds.
 Time taken by Merge Sort for a descending array with 300 values: 33 microseconds.
 Time taken by Merge Sort for a random array with 300 values: 50 microseconds.
         Arrays deleted, end of main reached. Resetting...
 Time taken by Bubble Sort for an ascending array with 500 values: 1 microseconds.
 Time taken by Bubble Sort for a descending array with 500 values: 836 microseconds.
 Time taken by Bubble Sort for a random array with 500 values: 781 microseconds.
 Time taken by Merge Sort for an ascending array with 500 values: 54 microseconds.
 Time taken by Merge Sort for a descending array with 500 values: 53 microseconds.
 Time taken by Merge Sort for a random array with 500 values: 85 microseconds.
         Arrays deleted, end of main reached. Resetting...
 Time taken by Bubble Sort for an ascending array with 1000 values: 2 microseconds.
 Time taken by Bubble Sort for a descending array with 1000 values: 3390 microseconds.
 Time taken by Bubble Sort for a random array with 1000 values: 3119 microseconds.
 Time taken by Merge Sort for an ascending array with 1000 values: 164 microseconds.
 Time taken by Merge Sort for a descending array with 1000 values: 158 microseconds.
 Time taken by Merge Sort for a random array with 1000 values: 198 microseconds.
         Arrays deleted, end of main reached. Resetting...
 Time taken by Bubble Sort for an ascending array with 3000 values: 6 microseconds.
 Time taken by Bubble Sort for a descending array with 3000 values: 30134 microseconds.
 Time taken by Bubble Sort for a random array with 3000 values: 31947 microseconds.
 Time taken by Merge Sort for an ascending array with 3000 values: 427 microseconds.
 Time taken by Merge Sort for a descending array with 3000 values: 406 microseconds.
 Time taken by Merge Sort for a random array with 3000 values: 992 microseconds.
         Arrays deleted, end of main reached. Resetting...
 Time taken by Bubble Sort for an ascending array with 5000 values: 10 microseconds.
 Time taken by Bubble Sort for a descending array with 5000 values: 85210 microseconds.
 Time taken by Bubble Sort for a random array with 5000 values: 96394 microseconds.
 Time taken by Merge Sort for an ascending array with 5000 values: 632 microseconds.
 Time taken by Merge Sort for a descending array with 5000 values: 621 microseconds.
 Time taken by Merge Sort for a random array with 5000 values: 1026 microseconds.
         Arrays deleted, end of main reached. Resetting...
 Time taken by Bubble Sort for an ascending array with 10000 values: 20 microseconds.
 Time taken by Bubble Sort for a descending array with 10000 values: 334580 microseconds.
 Time taken by Bubble Sort for a random array with 10000 values: 391759 microseconds.
 Time taken by Merge Sort for an ascending array with 10000 values: 1297 microseconds.
 Time taken by Merge Sort for a descending array with 10000 values: 1227 microseconds.
 Time taken by Merge Sort for a random array with 10000 values: 2148 microseconds.
         Arrays deleted, end of main reached. Resetting...
 Time taken by Bubble Sort for an ascending array with 50000 values: 102 microseconds.
 Time taken by Bubble Sort for a descending array with 50000 values: 8364460 microseconds.
 Time taken by Bubble Sort for a random array with 50000 values: 10638026 microseconds.
 Time taken by Merge Sort for an ascending array with 50000 values: 6769 microseconds.
 Time taken by Merge Sort for a descending array with 50000 values: 6595 microseconds.
 Time taken by Merge Sort for a random array with 50000 values: 11992 microseconds.
         Arrays deleted, end of main reached. Resetting...
 Program successfully ran.
 Program ended with exit code: 0
 */


 //If needed to print arrays:
 /*
  void resetNprint(int randomArray[], int ascArray[], int desArray[]) {
  cout << "\n\tResetting/Initializing arrays." << endl;
  initialize(randomArray, ascArray, desArray);
  printArrays(ascArray, desArray, randomArray, n);
 }
 */