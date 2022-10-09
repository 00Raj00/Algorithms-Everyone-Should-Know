#include<bits/stdc++.h>
using namespace std;

// Swap function
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// The function to construt heap (Max-Heap) 
void heapify(int arr[], int n, int i) {
    int largest = i;
    // Left child of the node
    int l = (2 * i) + 1;
    // Right child of the node
    int r = (2 * i) + 2;
    
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    // Finding largest element and swapping to maintian the heap recursively
    if (largest != i) {
        swap(&arr[largest], &arr[i]);
        heapify (arr, n, largest);
    }
}

// heapSort function 
void heapSort(int arr[], int n) {
    // Finding the last non - leaf node OR the last parent node in heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
		
	for (int i = n - 1; i > 0; i--) {
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

// Function to print an array
void printArray (int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

// Main function 
int main () {
    int arr[] = {25, 5, 12, 1, 63, 36};
    int n = 6;
    heapSort(arr, n);
    cout << "The Sorted Array is : ";
    printArray(arr, n);
    return 0;
}


