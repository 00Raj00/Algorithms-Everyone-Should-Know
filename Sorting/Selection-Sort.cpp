#include<bits/stdc++.h>
using namespace std;

// Function for swapping two numbers
void swap (int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Selection sort function
void selectionSort (int arr[], int n) {
    int i, j, min_index;
    // Two for loops for comparing two consecutive numbers and swapping it on the basis of the comparisons
    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap (&arr[min_index], &arr[i]);
        }
    }
}

// Function to print an array
void printArray (int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main () {
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;
    
    selectionSort(arr, n);
    printArray(arr, n);
    
    return 0;
}
