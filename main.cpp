#include "josh.h"
#include "andrew.h"

using namespace std;
using namespace std::chrono; //used for timekeeping.

void initialize(int randomArray[], int ascArray[], int desArray[]); //initaizes the three arrays for sorting.
void nSetup(); //assigns the n value associated to a local variable n.

int n;
int counter = 0; //used to increment to the correct n value.

//Works in XCode!

int main() {
    int choice;
    cout << "Task 1 or 2: ";
    cin >> choice;
    if (choice == 1) {
        while (counter != 8) { //counter != 8 coinsides each n variable. 100 is 0, 300 is 1, ... 50000 is 7.
            nSetup(); //initializes the correct n value.
            int* randomArray = new int[n];
            int* ascArray = new int[n];
            int* desArray = new int[n];

            initialize(randomArray, ascArray, desArray); //sets the arrays to their correct values.

            long long int bubbleSteps; //step counter for Bubble Sort.

            cout << "Bubble Sort: " << endl;

            auto start = high_resolution_clock::now(); //initializes the clock.
            bubbleSort(ascArray, n, bubbleSteps);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start); //calculates time taken in microseconds.

            cout << "Time taken by Bubble Sort for an ascending array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Bubble Sort for an ascending array with " << n << " values: " << bubbleSteps << " steps. " << endl;

            start = high_resolution_clock::now(); //repeat steps for descending array and random array.
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

            long long int mergeSteps; //step counter for Merge Sort.

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

            long long int heapSteps = 0;

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

            long long int quickSteps = 0;

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
            // if u run on windows and it doesn't work, replace with
            // delete[] ascArray, desArray, randomArray;

            cout << "\n\t\tArrays deleted, end of main reached. Resetting...\n" << endl;

            counter++; //counter to increment the n value.
        }
        cout << "Program successfully ran. " << endl;
        return 0;
    }
    else if (choice == 2) {
        //part 2
        ifstream inData;
        string filename = "";
        string algorithm;
        long long int totalSteps;
        long long int totalDuration;

        while (counter != 8) { 
            nSetup();
            filename = to_string(n) + ".txt";
            int* randomArray = new int[n];

            for (int i = 0; i < 4; i++) { // change to 6 later and edit switch - represents algos
                try {
                    inData.open(filename);
                }
                catch (exception e) {
                    cerr << "Unable to open file." << endl;
                    return 1;
                }

                totalSteps = 0;
                totalDuration = 0;

                for (int j = 0; j < 50; j++) {
                    for (int k = 0; k < n; k++) {
                        inData >> randomArray[k];
                    }

                    long long int steps = 0;

                    auto start = high_resolution_clock::now();
                    switch (i) {
                    case 0:
                        bubbleSort(randomArray, n, steps);
                        break;
                    case 1:
                        mergeSort(randomArray, 0, n - 1, steps);
                        break;
                    case 2:
                        HeapSort(randomArray, n, steps);
                        break;
                    case 3:
                        QuickSort(randomArray, 0, n - 1, steps);
                        break;

                    }
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);


                    totalDuration += duration.count();
                    totalSteps += steps;

                }
                inData.close();

                switch (i) {
                case 0:
                    algorithm = "Bubble Sort";
                    break;
                case 1:
                    algorithm = "Merge Sort";
                    break;
                case 2:
                    algorithm = "Heap Sort";
                    break;
                case 3:
                    algorithm = "Quick Sort";
                    break;

                }

                cout << algorithm << ": " << endl;
                cout << "Total time taken by " << algorithm << " for " << n << " values: " << totalDuration << " microseconds. " << endl;
                cout << "Total steps taken by " << algorithm << " for " << n << " values: " << totalSteps << " steps. " << endl;

                cout << "Average time taken by " << algorithm << " for " << n << " values: " << totalDuration / 50 << " microseconds. " << endl;
                cout << "Average steps taken by " << algorithm << " for " << n << " values: " << totalSteps / 50 << " steps. " << endl;

                cout << endl << endl;
            }
            counter++;
        }
        cout << "Program successfully ran." << endl;
        return 0;
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
    for (int i = 0; i < n; i++) { //sets the random array from 1 -> n. essentially scrambles an ascending array.
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

/* Windows 10, Ryzen 5 3600, 32 GB RAM 3600 mHz.
Bubble Sort:
Time taken by Bubble Sort for an ascending array with 100 values: 1 microseconds.
Steps taken by Bubble Sort for an ascending array with 100 values: 5 steps.

Time taken by Bubble Sort for a descending array with 100 values: 110 microseconds.
Steps taken by Bubble Sort for an descending array with 100 values: 25050 steps.

Time taken by Bubble Sort for a random array with 100 values: 64 microseconds.
Steps taken by Bubble Sort for an random array with 100 values: 11438 steps.

Merge Sort:
Time taken by Merge Sort for an ascending array with 100 values: 57 microseconds.
Steps taken by Merge Sort for an ascending array with 100 values: 1584 steps.

Time taken by Merge Sort for a descending array with 100 values: 53 microseconds.
Steps taken by Merge Sort for a descending array with 100 values: 1582 steps.

Time taken by Merge Sort for a random array with 100 values: 55 microseconds.
Steps taken by Merge Sort for a random array with 100 values: 1671 steps.

Heap Sort:
Time taken by Heap Sort for an ascending array with 100 values: 9 microseconds.
Steps taken by Heap Sort for an ascending array with 100 values: 12689 steps.

Time taken by HeapSort for a descending array with 100 values: 8 microseconds.
Steps taken by Heap Sort for an descending array with 100 values: 23229 steps.

Time taken by Heap Sort for a random array with 100 values: 23 microseconds.
Steps taken by Heap Sort for an random array with 100 values: 35054 steps.

Quick Sort:
Time taken by Quick Sort for an ascending array with 100 values: 20 microseconds.
Steps taken by Quick Sort for an ascending array with 100 values: 16534 steps.

Time taken by Quick Sort for a descending array with 100 values: 18 microseconds.
Steps taken by Quick Sort for a descending array with 100 values: 43068 steps.

Time taken by Quick Sort for a random array with 100 values: 6 microseconds.
Steps taken by Quick Sort for a random array with 100 values: 47917 steps.

                Arrays deleted, end of main reached. Resetting...

Bubble Sort:
Time taken by Bubble Sort for an ascending array with 300 values: 1 microseconds.
Steps taken by Bubble Sort for an ascending array with 300 values: 5 steps.

Time taken by Bubble Sort for a descending array with 300 values: 996 microseconds.
Steps taken by Bubble Sort for an descending array with 300 values: 225150 steps.

Time taken by Bubble Sort for a random array with 300 values: 605 microseconds.
Steps taken by Bubble Sort for an random array with 300 values: 106945 steps.

Merge Sort:
Time taken by Merge Sort for an ascending array with 300 values: 163 microseconds.
Steps taken by Merge Sort for an ascending array with 300 values: 4576 steps.

Time taken by Merge Sort for a descending array with 300 values: 157 microseconds.
Steps taken by Merge Sort for a descending array with 300 values: 4573 steps.

Time taken by Merge Sort for a random array with 300 values: 196 microseconds.
Steps taken by Merge Sort for a random array with 300 values: 4855 steps.

Heap Sort:
Time taken by Heap Sort for an ascending array with 300 values: 33 microseconds.
Steps taken by Heap Sort for an ascending array with 300 values: 48287 steps.

Time taken by HeapSort for a descending array with 300 values: 30 microseconds.
Steps taken by Heap Sort for an descending array with 300 values: 89393 steps.

Time taken by Heap Sort for a random array with 300 values: 34 microseconds.
Steps taken by Heap Sort for an random array with 300 values: 134278 steps.

Quick Sort:
Time taken by Quick Sort for an ascending array with 300 values: 122 microseconds.
Steps taken by Quick Sort for an ascending array with 300 values: 139634 steps.

Time taken by Quick Sort for a descending array with 300 values: 149 microseconds.
Steps taken by Quick Sort for a descending array with 300 values: 369268 steps.

Time taken by Quick Sort for a random array with 300 values: 20 microseconds.
Steps taken by Quick Sort for a random array with 300 values: 386336 steps.

                Arrays deleted, end of main reached. Resetting...

Bubble Sort:
Time taken by Bubble Sort for an ascending array with 500 values: 1 microseconds.
Steps taken by Bubble Sort for an ascending array with 500 values: 5 steps.

Time taken by Bubble Sort for a descending array with 500 values: 2988 microseconds.
Steps taken by Bubble Sort for an descending array with 500 values: 625250 steps.

Time taken by Bubble Sort for a random array with 500 values: 1737 microseconds.
Steps taken by Bubble Sort for an random array with 500 values: 300739 steps.

Merge Sort:
Time taken by Merge Sort for an ascending array with 500 values: 274 microseconds.
Steps taken by Merge Sort for an ascending array with 500 values: 7591 steps.

Time taken by Merge Sort for a descending array with 500 values: 262 microseconds.
Steps taken by Merge Sort for a descending array with 500 values: 7586 steps.

Time taken by Merge Sort for a random array with 500 values: 250 microseconds.
Steps taken by Merge Sort for a random array with 500 values: 8067 steps.

Heap Sort:
Time taken by Heap Sort for an ascending array with 500 values: 59 microseconds.
Steps taken by Heap Sort for an ascending array with 500 values: 87895 steps.

Time taken by HeapSort for a descending array with 500 values: 54 microseconds.
Steps taken by Heap Sort for an descending array with 500 values: 164100 steps.

Time taken by Heap Sort for a random array with 500 values: 61 microseconds.
Steps taken by Heap Sort for an random array with 500 values: 246397 steps.

Quick Sort:
Time taken by Quick Sort for an ascending array with 500 values: 312 microseconds.
Steps taken by Quick Sort for an ascending array with 500 values: 382734 steps.

Time taken by Quick Sort for a descending array with 500 values: 411 microseconds.
Steps taken by Quick Sort for a descending array with 500 values: 1015468 steps.

Time taken by Quick Sort for a random array with 500 values: 38 microseconds.
Steps taken by Quick Sort for a random array with 500 values: 1050062 steps.

                Arrays deleted, end of main reached. Resetting...

Bubble Sort:
Time taken by Bubble Sort for an ascending array with 1000 values: 2 microseconds.
Steps taken by Bubble Sort for an ascending array with 1000 values: 5 steps.

Time taken by Bubble Sort for a descending array with 1000 values: 11652 microseconds.
Steps taken by Bubble Sort for an descending array with 1000 values: 2500500 steps.

Time taken by Bubble Sort for a random array with 1000 values: 7378 microseconds.
Steps taken by Bubble Sort for an random array with 1000 values: 1217399 steps.

Merge Sort:
Time taken by Merge Sort for an ascending array with 1000 values: 485 microseconds.
Steps taken by Merge Sort for an ascending array with 1000 values: 15105 steps.

Time taken by Merge Sort for a descending array with 1000 values: 493 microseconds.
Steps taken by Merge Sort for a descending array with 1000 values: 15100 steps.

Time taken by Merge Sort for a random array with 1000 values: 542 microseconds.
Steps taken by Merge Sort for a random array with 1000 values: 16075 steps.

Heap Sort:
Time taken by Heap Sort for an ascending array with 1000 values: 131 microseconds.
Steps taken by Heap Sort for an ascending array with 1000 values: 197395 steps.

Time taken by HeapSort for a descending array with 1000 values: 120 microseconds.
Steps taken by Heap Sort for an descending array with 1000 values: 370063 steps.

Time taken by Heap Sort for a random array with 1000 values: 178 microseconds.
Steps taken by Heap Sort for an random array with 1000 values: 556035 steps.

Quick Sort:
Time taken by Quick Sort for an ascending array with 1000 values: 1184 microseconds.
Steps taken by Quick Sort for an ascending array with 1000 values: 1515484 steps.

Time taken by Quick Sort for a descending array with 1000 values: 1585 microseconds.
Steps taken by Quick Sort for a descending array with 1000 values: 4030968 steps.

Time taken by Quick Sort for a random array with 1000 values: 99 microseconds.
Steps taken by Quick Sort for a random array with 1000 values: 4099391 steps.

                Arrays deleted, end of main reached. Resetting...

Bubble Sort:
Time taken by Bubble Sort for an ascending array with 3000 values: 7 microseconds.
Steps taken by Bubble Sort for an ascending array with 3000 values: 5 steps.

Time taken by Bubble Sort for a descending array with 3000 values: 100605 microseconds.
Steps taken by Bubble Sort for an descending array with 3000 values: 22501500 steps.

Time taken by Bubble Sort for a random array with 3000 values: 64464 microseconds.
Steps taken by Bubble Sort for an random array with 3000 values: 10741075 steps.

Merge Sort:
Time taken by Merge Sort for an ascending array with 3000 values: 1452 microseconds.
Steps taken by Merge Sort for an ascending array with 3000 values: 45097 steps.

Time taken by Merge Sort for a descending array with 3000 values: 1502 microseconds.
Steps taken by Merge Sort for a descending array with 3000 values: 45091 steps.

Time taken by Merge Sort for a random array with 3000 values: 1681 microseconds.
Steps taken by Merge Sort for a random array with 3000 values: 48072 steps.

Heap Sort:
Time taken by Heap Sort for an ascending array with 3000 values: 456 microseconds.
Steps taken by Heap Sort for an ascending array with 3000 values: 700075 steps.

Time taken by HeapSort for a descending array with 3000 values: 446 microseconds.
Steps taken by Heap Sort for an descending array with 3000 values: 1321429 steps.

Time taken by Heap Sort for a random array with 3000 values: 477 microseconds.
Steps taken by Heap Sort for an random array with 3000 values: 1983853 steps.

Quick Sort:
Time taken by Quick Sort for an ascending array with 3000 values: 10799 microseconds.
Steps taken by Quick Sort for an ascending array with 3000 values: 13546484 steps.

Time taken by Quick Sort for a descending array with 3000 values: 14283 microseconds.
Steps taken by Quick Sort for a descending array with 3000 values: 36092968 steps.

Time taken by Quick Sort for a random array with 3000 values: 264 microseconds.
Steps taken by Quick Sort for a random array with 3000 values: 36317031 steps.

                Arrays deleted, end of main reached. Resetting...

Bubble Sort:
Time taken by Bubble Sort for an ascending array with 5000 values: 11 microseconds.
Steps taken by Bubble Sort for an ascending array with 5000 values: 5 steps.

Time taken by Bubble Sort for a descending array with 5000 values: 279913 microseconds.
Steps taken by Bubble Sort for an descending array with 5000 values: 62502500 steps.

Time taken by Bubble Sort for a random array with 5000 values: 185222 microseconds.
Steps taken by Bubble Sort for an random array with 5000 values: 30286629 steps.

Merge Sort:
Time taken by Merge Sort for an ascending array with 5000 values: 2686 microseconds.
Steps taken by Merge Sort for an ascending array with 5000 values: 75125 steps.

Time taken by Merge Sort for a descending array with 5000 values: 2699 microseconds.
Steps taken by Merge Sort for a descending array with 5000 values: 75121 steps.

Time taken by Merge Sort for a random array with 5000 values: 2833 microseconds.
Steps taken by Merge Sort for a random array with 5000 values: 80096 steps.

Heap Sort:
Time taken by Heap Sort for an ascending array with 5000 values: 830 microseconds.
Steps taken by Heap Sort for an ascending array with 5000 values: 1246529 steps.

Time taken by HeapSort for a descending array with 5000 values: 756 microseconds.
Steps taken by Heap Sort for an descending array with 5000 values: 2361879 steps.

Time taken by Heap Sort for a random array with 5000 values: 866 microseconds.
Steps taken by Heap Sort for an random array with 5000 values: 3545812 steps.

Quick Sort:
Time taken by Quick Sort for an ascending array with 5000 values: 28560 microseconds.
Steps taken by Quick Sort for an ascending array with 5000 values: 37577484 steps.

Time taken by Quick Sort for a descending array with 5000 values: 38581 microseconds.
Steps taken by Quick Sort for a descending array with 5000 values: 100154968 steps.

Time taken by Quick Sort for a random array with 5000 values: 498 microseconds.
Steps taken by Quick Sort for a random array with 5000 values: 100578519 steps.

                Arrays deleted, end of main reached. Resetting...

Bubble Sort:
Time taken by Bubble Sort for an ascending array with 10000 values: 23 microseconds.
Steps taken by Bubble Sort for an ascending array with 10000 values: 5 steps.

Time taken by Bubble Sort for a descending array with 10000 values: 1164300 microseconds.
Steps taken by Bubble Sort for an descending array with 10000 values: 250005000 steps.

Time taken by Bubble Sort for a random array with 10000 values: 748842 microseconds.
Steps taken by Bubble Sort for an random array with 10000 values: 119454337 steps.

Merge Sort:
Time taken by Merge Sort for an ascending array with 10000 values: 5363 microseconds.
Steps taken by Merge Sort for an ascending array with 10000 values: 150139 steps.

Time taken by Merge Sort for a descending array with 10000 values: 5277 microseconds.
Steps taken by Merge Sort for a descending array with 10000 values: 150135 steps.

Time taken by Merge Sort for a random array with 10000 values: 5721 microseconds.
Steps taken by Merge Sort for a random array with 10000 values: 160113 steps.

Heap Sort:
Time taken by Heap Sort for an ascending array with 10000 values: 1779 microseconds.
Steps taken by Heap Sort for an ascending array with 10000 values: 2709315 steps.

Time taken by HeapSort for a descending array with 10000 values: 1658 microseconds.
Steps taken by Heap Sort for an descending array with 10000 values: 5154607 steps.

Time taken by Heap Sort for a random array with 10000 values: 1894 microseconds.
Steps taken by Heap Sort for an random array with 10000 values: 7731079 steps.

Quick Sort:
Time taken by Quick Sort for an ascending array with 10000 values: 112468 microseconds.
Steps taken by Quick Sort for an ascending array with 10000 values: 150154984 steps.

Time taken by Quick Sort for a descending array with 10000 values: 155068 microseconds.
Steps taken by Quick Sort for a descending array with 10000 values: 400309968 steps.

Time taken by Quick Sort for a random array with 10000 values: 995 microseconds.
Steps taken by Quick Sort for a random array with 10000 values: 401185292 steps.

                Arrays deleted, end of main reached. Resetting...

Bubble Sort:
Time taken by Bubble Sort for an ascending array with 50000 values: 117 microseconds.
Steps taken by Bubble Sort for an ascending array with 50000 values: 5 steps.

Time taken by Bubble Sort for a descending array with 50000 values: 28214377 microseconds.
Steps taken by Bubble Sort for an descending array with 50000 values: 6250025000 steps.

Time taken by Bubble Sort for a random array with 50000 values: 19528917 microseconds.
Steps taken by Bubble Sort for an random array with 50000 values: 3374410886 steps.

Merge Sort:
Time taken by Merge Sort for an ascending array with 50000 values: 27378 microseconds.
Steps taken by Merge Sort for an ascending array with 50000 values: 750189 steps.

Time taken by Merge Sort for a descending array with 50000 values: 26809 microseconds.
Steps taken by Merge Sort for a descending array with 50000 values: 750184 steps.

Time taken by Merge Sort for a random array with 50000 values: 28691 microseconds.
Steps taken by Merge Sort for a random array with 50000 values: 799203 steps.

Heap Sort:
Time taken by Heap Sort for an ascending array with 50000 values: 10537 microseconds.
Steps taken by Heap Sort for an ascending array with 50000 values: 16027219 steps.

Time taken by HeapSort for a descending array with 50000 values: 10028 microseconds.
Steps taken by Heap Sort for an descending array with 50000 values: 30738729 steps.

Time taken by Heap Sort for a random array with 50000 values: 11358 microseconds.
Steps taken by Heap Sort for an random array with 50000 values: 46019707 steps.

Quick Sort:
Time taken by Quick Sort for an ascending array with 50000 values: 2807079 microseconds.
Steps taken by Quick Sort for an ascending array with 50000 values: 3750774984 steps.

Time taken by Quick Sort for a descending array with 50000 values: 3865914 microseconds.
Steps taken by Quick Sort for a descending array with 50000 values: 10001549968 steps.

Time taken by Quick Sort for a random array with 50000 values: 5766 microseconds.
Steps taken by Quick Sort for a random array with 50000 values: 10006704964 steps.

                Arrays deleted, end of main reached. Resetting...

Program successfully ran.
*/