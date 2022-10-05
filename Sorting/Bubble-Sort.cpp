#include <iostream>
using namespace std;

// Function for swapping two numbers
void swap (int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

//Bubble sort function 
void bubbleSort (int arr[], int n) {
    // Comparing two adjacent element, if the 2nd element is smaller then it is swapped else move on
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap (&arr[j], &arr[j + 1]);
            }    
        }
    }
}

//Function for printing an array 
void printArray (int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main () {
    int arr[] = {25, 6, 12, 99, 10};
    int n = 5;
    bubbleSort (arr, n);
    printArray(arr, n);
    return 0;
}
