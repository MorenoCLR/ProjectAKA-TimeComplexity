/*
Analysis of Restaurant Sorting Algorithms
Based on Ratings in Online Delivery Apps
*/

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

struct restaurant{
    string name;
    float rating;
};

void input(restaurant*& arr, int &NMAX) {
    ifstream input("example.txt");

    // Error Checking
    if (!input.is_open()) {
        cerr << "Error: Could not open the file!" << endl;
        return;
    }

    // Reading Requirements
    input >> NMAX;

    // Allocate
    arr = new restaurant[NMAX];

    // Reading Restaurant Data
    int i = 0;
    while (i < NMAX && input >> arr[i].name >> arr[i].rating){
        i++;
    }

    input.close();
}

void print(restaurant arr[], int NMAX){
    for (int i=0; i < NMAX; i++){
        cout << arr[i].name << " " << arr[i].rating << endl;
    }
    cout << endl;
}


void mergeSort(restaurant arr[], int n) {
    for (int current_size = 1; current_size < n; current_size *= 2) {
        for (int left = 0; left < n - 1; left += 2 * current_size) {
            int mid = min(left + current_size - 1, n - 1);
            int right = min(left + 2 * current_size - 1, n - 1);

            // Temporary array for merging
            restaurant temp[right - left + 1];
            int i = left, j = mid + 1, k = 0;

            // Merge two sorted subarrays
            while (i <= mid && j <= right) {
                if (arr[i].rating >= arr[j].rating) { // Sort by rating (descending)
                    temp[k++] = arr[i++];
                } else {
                    temp[k++] = arr[j++];
                }
            }
            while (i <= mid){
                temp[k++] = arr[i++];
            }
            while (j <= right){
                temp[k++] = arr[j++];
            }
            // Copy the sorted array back to the original
            for (k = 0; k < (right - left + 1); k++) {
                arr[left + k] = temp[k];
            }
        }
    }
}

void recursiveMergeSort(restaurant arr[], int left, int right) {
    if (left >= right){
        return; // Base case
    }

    int mid = left + (right - left) / 2;

    // Recursively sort the two halves
    recursiveMergeSort(arr, left, mid);
    recursiveMergeSort(arr, mid + 1, right);

    // Merge the two halves
    restaurant temp[right - left + 1];
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i].rating >= arr[j].rating) { // Sort by rating (descending)
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid){
       temp[k++] = arr[i++];
    }
    while (j <= right){
        temp[k++] = arr[j++];
    }

    // Copy sorted elements back to the original array
    for (k = 0; k < (right - left + 1); k++) {
        arr[left + k] = temp[k];
    }
}

int main() {
    int NMAX;
    const int runs = 1000;
    double totalIterativeTime = 0.0, totalRecursiveTime = 0.0;
    high_resolution_clock::time_point iterativeStart, iterativeEnd, recursiveStart, recursiveEnd;


    for (int run = 1; run <= runs; run++) {
        restaurant* arr = NULL;
        input(arr,NMAX);
        restaurant* iterativeArr = new restaurant[NMAX];
        for (int i = 0; i < NMAX; i++) {
            iterativeArr[i] = arr[i];
        }
        restaurant* recursiveArr = new restaurant[NMAX];
            for (int i = 0; i < NMAX; i++) {
            recursiveArr[i] = arr[i];
        }

        cout << "Processing " << NMAX << " restaurants " <<endl;
        iterativeStart = high_resolution_clock::now();
        mergeSort(iterativeArr, NMAX);
        iterativeEnd = high_resolution_clock::now();

        recursiveStart = high_resolution_clock::now();
        recursiveMergeSort(recursiveArr, 0, NMAX-1);
        recursiveEnd = high_resolution_clock::now();
        cout << endl;

//    cout << "================= Iterative =================" << endl;
//    print(iterativeArr, NMAX);
//    cout << endl;
//
//    cout << "================= Recursive =================" << endl;
//    print(recursiveArr, NMAX);
//    cout << endl;

        duration<double> iterativeElapsed = iterativeEnd - iterativeStart;
        totalIterativeTime += iterativeElapsed.count();

        duration<double> recursiveElapsed = recursiveEnd - recursiveStart;
        totalRecursiveTime += recursiveElapsed.count();

        delete[] arr;
        delete[] iterativeArr;
        delete[] recursiveArr;

        cout << "Run " << run << "/" << runs << " completed." << endl;
    }
    double averageIterativeTime = totalIterativeTime / runs;
    double averageRecursiveTime = totalRecursiveTime / runs;

    cout << "Finished Processing " << NMAX << " restaurants " << endl;
    cout << "Iterative:" << endl;
    cout << "Average Merge Sort time: " << fixed << setprecision(10) << averageIterativeTime << " seconds\n";
    cout << endl;

    cout << "Recursive:" << endl;
    cout << "Average Merge Sort time: " << fixed << setprecision(10) << averageRecursiveTime << " seconds\n";


    return 0;
}
