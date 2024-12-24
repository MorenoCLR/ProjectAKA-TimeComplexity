//#include <iostream>
//#include <fstream>
//#include <string>
//#include <chrono>
//#include <iomanip>
//
//using namespace std;
//using namespace chrono;
//
//struct restaurant{
//    string name;
//    float rating;
//};
//
//void input(restaurant*& arr, int &NMAX, int &Choice) {
//    ifstream input("example.txt");
//
//    // Error Checking
//    if (!input.is_open()) {
//        cerr << "Error: Could not open the file!" << endl;
//        return;
//    }
//
//    // Reading Requirements
//    input >> NMAX >> Choice;
//
//    // Allocate
//    arr = new restaurant[NMAX];
//
//    // Reading Restaurant Data
//    int i = 0;
//    while (i < NMAX && input >> arr[i].name >> arr[i].rating){
//        i++;
//    }
//
//    input.close();
//}
//
//void print(restaurant arr[], int NMAX){
//    for (int i=0; i < NMAX; i++){
//        cout << arr[i].name << " " << arr[i].rating << endl;
//    }
//    cout << endl;
//}
//
//
//void mergeIterative(restaurant arr[], restaurant temp[], int left, int mid, int right) {
//    int i = left, j = mid + 1, k = left;
//    while (i <= mid && j <= right) {
//        if (arr[i].rating >= arr[j].rating) {
//            temp[k++] = arr[i++];
//        } else {
//            temp[k++] = arr[j++];
//        }
//    }
//    while (i <= mid) {
//        temp[k++] = arr[i++];
//    }
//    while (j <= right) {
//        temp[k++] = arr[j++];
//    }
//    for (int x = left; x <= right; x++) {
//        arr[x] = temp[x];
//    }
//}
//
//void mergeRecursive(restaurant arr[], int left, int mid, int right) {
//    int n1 = mid - left + 1;
//    int n2 = right - mid;
//    restaurant L[n1], R[n2];
//
//    for (int i = 0; i < n1; i++)
//        L[i] = arr[left + i];
//    for (int j = 0; j < n2; j++)
//        R[j] = arr[mid + 1 + j];
//
//    int i = 0, j = 0, k = left;
//    while (i < n1 && j < n2) {
//        if (L[i].rating >= R[j].rating) {
//            arr[k++] = L[i++];
//        } else {
//            arr[k++] = R[j++];
//        }
//    }
//    while (i < n1) {
//        arr[k++] = L[i++];
//    }
//    while (j < n2) {
//        arr[k++] = R[j++];
//    }
//}
//
//void iterativeMergeSort(restaurant arr[], int n) {
//    restaurant temp[n];
//    for (int size = 1; size < n; size *= 2) {
//        for (int left = 0; left < n - 1; left += 2 * size) {
//            int mid = min(left + size - 1, n - 1);
//            int right = min(left + 2 * size - 1, n - 1);
//            mergeIterative(arr, temp, left, mid, right);
//        }
//    }
//}
//
//void recursiveMergeSort(restaurant arr[], int left, int right) {
//    if (left < right) {
//        int mid = left + (right - left) / 2;
//        recursiveMergeSort(arr, left, mid);
//        recursiveMergeSort(arr, mid + 1, right);
//        mergeRecursive(arr, left, mid, right);
//    }
//}
//
//int main() {
//    int NMAX;
//    int choice;
//    high_resolution_clock::time_point Start, End;
//    restaurant* arr = NULL;
//    input(arr,NMAX,choice);
//
//    cout << "Processing " << NMAX << " restaurants ";
//    if (choice == 1) {
//        cout << "in iterative" << endl;
//        Start = high_resolution_clock::now();
//        iterativeMergeSort(arr, NMAX);
//        End = high_resolution_clock::now();
//    } else {
//        cout << "in recursive" << endl;
//        Start = high_resolution_clock::now();
//        recursiveMergeSort(arr, 0, NMAX - 1);
//        End = high_resolution_clock::now();
//    }
//    print(arr,NMAX);
//
//    cout << "Finished Processing " << NMAX << " restaurants ";
//    if (choice == 1){
//        cout << "in iterative" << endl;
//        duration<double> elapsed = End - Start;
//        cout << "Elapsed time: " << fixed << setprecision(10) << elapsed.count() << " seconds\n";
//        cout << "In example.txt change to 2 if you want to try recursive." << endl;
//    } else {
//        cout << "in recursive" << endl;
//        duration<double> elapsed = End - Start;
//        cout << "Elapsed time: " << fixed << setprecision(10) << elapsed.count() << " seconds\n";
//        cout << "In example.txt change to 1 if you want to try recursive." << endl;
//    }
//    return 0;
//}
