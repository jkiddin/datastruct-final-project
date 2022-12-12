#include "josh.h"
#include "andrew.h"
#include "hannah.h"

using namespace std;
using namespace std::chrono; //used for timekeeping.

void initialize(int randomArray[], int ascArray[], int desArray[]); //initaizes the three arrays for sorting.
void nSetup(); //assigns the n value associated to a local variable n.

int n;
int counter = 0; //used to increment to the correct n value.

//Works in XCode!
//https://pastebin.com/svweXHTg

int main() {
    int choice;
    cout << "Task 1 or 2: ";
    cin >> choice;
    cout << '\n';
    if (choice == 1) {
        while (counter != 4) { //counter != 8 coinsides each n variable. 100 is 0, 300 is 1, ... 50000 is 7.
            nSetup(); //initializes the correct n value.
            int* randomArray = new int[n];
            int* ascArray = new int[n];
            int* desArray = new int[n];

            initialize(randomArray, ascArray, desArray); //sets the arrays to their correct values.

            cout << '\n';
            initialize(randomArray, ascArray, desArray);

            long long int InsertionSteps = 0;

            cout << "Insertion Sort: " << endl;

            auto start = high_resolution_clock::now();
            InsertionSort(ascArray, n, InsertionSteps);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);

            cout << "Time taken by Insertion Sort for an ascending array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Insertion Sort for an ascending array with " << n << " values: " << InsertionSteps << " steps. " << endl;
            
            InsertionSteps = 0;

            start = high_resolution_clock::now();
            InsertionSort(desArray, n, InsertionSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);

            cout << "\nTime taken by Insertion Sort for a descending array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Insertion Sort for an descending array with " << n << " values: " << InsertionSteps << " steps. " << endl;
            
            InsertionSteps = 0;

            start = high_resolution_clock::now();
            InsertionSort(randomArray, n, InsertionSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);

            cout << "\nTime taken by Insertion Sort for a random array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Insertion Sort for an random array with " << n << " values: " << InsertionSteps << " steps. " << endl;

            cout << '\n';
            initialize(randomArray, ascArray, desArray);

            //Selection Sort
            long long int SelectionSteps = 0;

            cout << "Selection Sort: " << endl;

            start = high_resolution_clock::now();
            SelectionSort(ascArray, n, SelectionSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);

            cout << "Time taken by Selection Sort for an ascending array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Selection Sort for an ascending array with " << n << " values: " << SelectionSteps << " steps. " << endl;
            
            SelectionSteps = 0;

            start = high_resolution_clock::now();
            SelectionSort(desArray, n, SelectionSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);

            cout << "\nTime taken by Selection Sort for a descending array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Selection Sort for a descending array with " << n << " values: " << SelectionSteps << " steps. " << endl;
            
            SelectionSteps = 0;

            start = high_resolution_clock::now();
            SelectionSort(randomArray, n, SelectionSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);

            cout << "\nTime taken by Selection Sort for a random array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Selection Sort for a random array with " << n << " values: " << SelectionSteps << " steps. " << endl;
            //end Hannah's
            
            //start josh
            cout << '\n';
            initialize(randomArray, ascArray, desArray);
            
            long long int bubbleSteps = 0; //step counter for Bubble Sort.

            cout << "Bubble Sort: " << endl;

            start = high_resolution_clock::now(); //initializes the clock.
            bubbleSort(ascArray, n, bubbleSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start); //calculates time taken in microseconds.

            cout << "Time taken by Bubble Sort for an ascending array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Bubble Sort for an ascending array with " << n << " values: " << bubbleSteps << " steps. " << endl;

            bubbleSteps = 0;

            start = high_resolution_clock::now(); //repeat steps for descending array and random array.
            bubbleSort(desArray, n, bubbleSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);

            cout << "\nTime taken by Bubble Sort for a descending array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Bubble Sort for an descending array with " << n << " values: " << bubbleSteps << " steps. " << endl;

            bubbleSteps = 0;

            start = high_resolution_clock::now();
            bubbleSort(randomArray, n, bubbleSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);

            cout << "\nTime taken by Bubble Sort for a random array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Bubble Sort for an random array with " << n << " values: " << bubbleSteps << " steps. " << endl;

            cout << '\n';
            initialize(randomArray, ascArray, desArray);

            long long int mergeSteps = 0; //step counter for Merge Sort.

            cout << "Merge Sort: " << endl;

            start = high_resolution_clock::now();
            mergeSort(ascArray, 0, n - 1, mergeSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);

            cout << "Time taken by Merge Sort for an ascending array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Merge Sort for an ascending array with " << n << " values: " << mergeSteps << " steps. " << endl;

            mergeSteps = 0;

            start = high_resolution_clock::now();
            mergeSort(desArray, 0, n - 1, mergeSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);

            cout << "\nTime taken by Merge Sort for a descending array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Merge Sort for a descending array with " << n << " values: " << mergeSteps << " steps. " << endl;

            mergeSteps = 0;

            start = high_resolution_clock::now();
            mergeSort(randomArray, 0, n - 1, mergeSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);

            cout << "\nTime taken by Merge Sort for a random array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Merge Sort for a random array with " << n << " values: " << mergeSteps << " steps. " << endl;

            //end josh
           
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

            cout << "\nTime taken by Heap Sort for a descending array with " << n << " values: " << duration.count() << " microseconds. " << endl;
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
            
            quickSteps = 0;

            start = high_resolution_clock::now();
            QuickSort(desArray, 0, n - 1, quickSteps);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);

            cout << "\nTime taken by Quick Sort for a descending array with " << n << " values: " << duration.count() << " microseconds. " << endl;
            cout << "Steps taken by Quick Sort for a descending array with " << n << " values: " << quickSteps << " steps. " << endl;

            quickSteps = 0;
            
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

        while (counter != 4) {
            nSetup();
            filename = to_string(n) + ".txt";
            int* randomArray = new int[n];

            for (int i = 0; i < 4; i++) { // change to 6 later and edit switch - represents algos
                inData.open(filename);
                if (!inData.is_open()) {
                    cerr << "File " << filename << " is not open. " << endl;
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
            delete[] randomArray;
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
 - See spreadsheet for accurate results.
*/
