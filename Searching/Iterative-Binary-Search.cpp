#include <bits/stdc++.h>
using namespace std;

/* 
This function keeps on dividing the array into two parts, until it reaches to single element.
Index of the element is returned if element is present in the array,
*/

int binarySearch(int arr[], int l, int h, int x) {
	while (l <= h) {
		int m = (l + h) / 2;
		if (arr[m] == x)
			return m;
		if (arr[m] < x)
			l = m + 1;
		else
			h = m - 1;
	}
	// -1 is returned if element is not present in the given array.
	return -1;
}

int main(void) {
	int arr[] = {2, 5, 6, 10, 45};
	int n = 5;
	int x = 10;
	int result = binarySearch(arr, 0, n - 1, x);
	if (result == -1)
        cout << "Element is not found";
    else
        cout << "Element is found at index: " << result;
	return 0;
}
