#include<bits/stdc++.h>
using namespace std;

// Swap function 
void swap (int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* 
This is partition function which returns the index of the element from which partition has to be made
*/
int partition (int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    do {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap (&arr[i], &arr[j]);
        }
    } while (i < j);
    // If i and j crosses each other then swap element of 'j' with pivot element
    swap (&arr[low], &arr[j]);
    return j;
}

void quickSort (int arr[], int low, int  high) {
    if (low < high) {
        // Finding the index of partitioned element
        int p_index = partition (arr, low, high);
        // Applying quickSort recursively in the left sub-array
        quickSort (arr, low, p_index - 1);
        // Applying quickSort recursively in the Right sub-array
        quickSort (arr, p_index + 1, high);
    }
}

// Function to print the array
void printArray (int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

// Main funtion
int main () {
    int arr[] = {29, 21, 6, 24, 30, 17};
    int n = 6;
    quickSort(arr, 0, n - 1);
    cout << "Sorted Array is : ";
    printArray(arr, n);
    return 0;
}

