#include<bits/stdc++.h>
using namespace std;

class Graph {
    // No. of vertices in graph
	int V;
	// Pointer to an array
	vector<list<int>> adj;
public:
    // Constructor (note: it does not have a return tyoe )
	Graph(int V);
	// function to add an edge to the graph
	void addEdge(int v, int w);
	// prints BFS traversal from a given source
	void BFS(int s);
};

Graph::Graph(int V) {
	this->V = V;
	adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    // Add w to v's list
	adj[v].push_back(w);
}

void Graph::BFS(int s) {
	vector<bool> visited;
	// Mark all the vertices as not visited
	visited.resize(V,false);
	// Create a queue for BFS
	list<int> queue;
	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	while(!queue.empty()) {
		// Dequeue a vertex from queue and print it
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		// If a adjacent has not been visited, then mark it visited and enqueue it
		for (auto adjecent: adj[s]) {
			if (!visited[adjecent]) {
				visited[adjecent] = true;
				queue.push_back(adjecent);
			}
		}
	}
}

// Main function
int main() {
	// Create a graph given in the above diagram
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "The BFS traversal (start = 1) is : " << endl;
	g.BFS(1);

	return 0;
}
