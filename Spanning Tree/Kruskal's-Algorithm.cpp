#include <bits/stdc++.h>
using namespace std;

// Class known as Disjoint Set Union OR DSU
// Path compression + rank by union is Used
class DSU {
	int* parent;
	int* rank;

public:
	DSU(int n) {
		parent = new int[n];
		rank = new int[n];

		for (int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	// Find function
	int find(int i) {
		if (parent[i] == -1)
			return i;
		return parent[i] = find(parent[i]);
	}

	// Union function
	void unite(int x, int y) {
		int s1 = find(x);
		int s2 = find(y);

		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}
};

class Graph {
    // Declaring a vector named edgelist
	vector<vector<int>> edgelist;
	int V;

public:
	Graph(int V) { 
	    this->V = V;
    }

	void addEdge(int x, int y, int w) {
	    // push_back() is a STL function
		edgelist.push_back({ w, x, y });
	}

	void kruskals_mst() {
		// Pre defined sort function in c++
		sort(edgelist.begin(), edgelist.end());
		
		// Initializing the DSU
		DSU s(V);
		int ans = 0;
		cout << "These are the edges in the constructed MST" << endl;
		
		// Another way of writing for loop in C++
		for (auto edge : edgelist) {
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];

			// Include the edge in MST if it does not forms a cycle
			if (s.find(x) != s.find(y)) {
				s.unite(x, y);
				ans += w;
				cout << x << " -- " << y << " == " << w << endl;
			}
		}
		cout << "Minimum Cost Spanning Tree is : " << ans;
	}
};

// Main Function 
int main() {
	Graph g(4);
	g.addEdge(0, 1, 10);
	g.addEdge(1, 3, 15);
	g.addEdge(2, 3, 4);
	g.addEdge(2, 0, 6);
	g.addEdge(0, 3, 5);

	g.kruskals_mst();
	return 0;
}

