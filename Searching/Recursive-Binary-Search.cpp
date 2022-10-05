#include <bits/stdc++.h>
using namespace std;

/*
This is the recursive function of binary search which calls itself until the element is found.
Returns the index of the element if the element is present in the array.
*/

int binarySearch(int arr[], int l, int h, int x) {
	if (h >= l) {
		int mid = (l + h) / 2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
		// Calling the left half of the array.
			return binarySearch(arr, l, mid - 1, x);
			// Calling the right half of the array.
		return binarySearch(arr, mid + 1, h, x);
	}
	
	// returns -1 as the index if element is not present in the array.
	return -1;
}

int main(void) {
	int arr[] = { 2, 5, 6, 10, 45};
	int n = 5;
	int x = 4;
	int result = binarySearch(arr, 0, n - 1, x);
	if (result == -1)
		cout << "Element is not found";
	else 
		cout << "Element is found at index : "<< result;
	return 0;
}

