#include <bits/stdc++.h>
using namespace std;
#define V 5

// Function to find the vertex with minimum value which is not included in MST 
int minKey(int key[], bool mstSet[]) {
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;
	return min_index;
}

// Function to print the MST 
void printMST(int parent[], int graph[V][V]) {
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

// Function to construct MST 
void primMST(int graph[V][V]) {
	// Array to store MST
	int parent[V];
	int key[V];
	bool mstSet[V];

	// Initializing all keys as INFINITE
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;
	key[0] = 0;
	// First node is always root of MST 
	parent[0] = -1;

	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum key which is not included
		int u = minKey(key, mstSet);
		// Add the picked one to MST 
		mstSet[u] = true;
		// Updating the key value in the adjacency Matrix
		for (int v = 0; v < V; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}
	printMST(parent, graph);
}

// Main Function 
int main() {
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };
	primMST(graph);
	return 0;
}


