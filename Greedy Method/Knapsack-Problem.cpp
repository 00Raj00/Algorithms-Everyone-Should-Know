#include <bits/stdc++.h>
using namespace std;

// Creating structure to store value and weight of the object
struct Item {
	int value, weight;
	Item(int value, int weight) {
		this->value = value;
		this->weight = weight;
	}
};

bool cmp(struct Item a, struct Item b) {
	double r1 = (double)a.value / (double)a.weight;
	double r2 = (double)b.value / (double)b.weight;
	return r1 > r2;
}

double fractionalKnapsack(int W, struct Item arr[], int N) {
	sort(arr, arr + N, cmp);
	double finalvalue = 0.0;

	for (int i = 0; i < N; i++) {
		if (arr[i].weight <= W) {
			W -= arr[i].weight;
			finalvalue += arr[i].value;
		}
		// If the weight of the object is exceeding the capacity then fractional part is taken
		else {
			finalvalue += arr[i].value * ((double)W / (double)arr[i].weight);
			break;
		}
	}
	return finalvalue;
}

int main() {
	int W = 40;
	Item arr[] = {{ 69, 10 }, { 200, 20 }, { 90, 30 }};
	int N = sizeof(arr) / sizeof(arr[0]);

	cout << "Maximum Profit we get is = " << fractionalKnapsack(W, arr, N);
	return 0;
}

