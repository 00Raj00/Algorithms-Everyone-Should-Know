#include <bits/stdc++.h>
using namespace std;
#define V 9

// Function to find the minimum distance of the vertex which is not yet included
int minDistance(int dist[], bool sptSet[]) {
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
	return min_index;
}

// Function to print all the distance 
void printSolution(int dist[]) {
	cout << "\tVertex \t\t Distance from Source" << endl;
	for (int i = 0; i < V; i++)
		cout << "\t" << i << " \t\t\t" << dist[i] << endl;
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int graph[V][V], int src) {
    // This int will hold the shortest distance from source to vertex 'V'
	int dist[V];
	//This bool will show if the vertex is included of not 'true' if included and 'false' if not included.
	bool sptSet[V];

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
	    // Initializing all the distance as infinte and sptSet as 'false' as no vertex is included as of now.
		dist[i] = INT_MAX, sptSet[i] = false;
	// distance from source to source is 0
	dist[src] = 0;
	
	// Loop to find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Picking the vertex which is not yet included in the set
		int u = minDistance(dist, sptSet);
		// Set it as true if included
		sptSet[u] = true;
		
		// Loop to update the distance of the chosen vertex which is still not included in the set 
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	
	// Function call to print the distance 
	printSolution(dist);
}

// Main Function
int main() {
    // Initializing the graph into the adjacency matrix.
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	dijkstra(graph, 0);
	return 0;
}
