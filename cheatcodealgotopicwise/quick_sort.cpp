#include <iostream>
#include <vector>

using namespace std;

// Function to partition the array and return the pivot index
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Swap the pivot element with the element at (i + 1), putting the pivot in its correct position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform the QuickSort algorithm
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the sub-arrays
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    // Example usage
    vector<int> arr = {12, 7, 1, 5, 9, 2, 8, 3};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    int n = arr.size();
    
    // Perform QuickSort
    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
