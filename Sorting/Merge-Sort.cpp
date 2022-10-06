#include<bits/stdc++.h>
using namespace std;

// The function to merge the two array while sorting the elements simultaneously
void merge (int arr[], int low, int mid, int high) {
    int i, j, k, arr2[100];
    i = low;
    j = mid + 1;
    k = low;
    // Comparing and placing the smallest element int he arr2[] 
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            arr2[k] = arr[i];
            i++; k++;
        }
        else {
            arr2[k] = arr[j];
            j++; k++;
        }
    }
    while (i <= mid) {
        arr2[k] = arr[i];
        k++; i++;
    }
    while (j <= high) {
        arr2[k] = arr[j];
        k++; j++;
    }
    // Loop for merging the remaining elements from any of the two arrays in arr2[] 
    for (i = low; i <= high; i++) {
        arr[i] = arr2[i];
    }
}

// This funtion recursively divides the array and merging them together
void mergeSort (int arr[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        // Recursive function for Left sub-array
        mergeSort(arr, low, mid);
        // Recursive function for Right sub-array
        mergeSort(arr, mid + 1, high);
        // Merge funtion 
        merge(arr, low, mid, high);
    }
}

// function to print the array 
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

// Main function
int main () {
    int arr[] = {12, 11, 13, 5, 7, 6};
    int n = 6;
    mergeSort(arr, 0, 5);
    
    cout << "Sorted Array is: ";
    printArray(arr, n);
}


