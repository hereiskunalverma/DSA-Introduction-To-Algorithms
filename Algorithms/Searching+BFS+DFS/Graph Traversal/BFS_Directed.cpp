/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-06-22 12:08:26  (IST)
*/

#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

// Breadth First Search  - starting from a given node


// Below is the implementation of the image .... https://media.geeksforgeeks.org/wp-content/uploads/bfs-5.png


// We are using a Directed - UnWeighted Graph using adjacency list

// function to add an edge between two vertices / nodes
void addEdge(vector<int> adjList[], int u, int v) {
	adjList[u].push_back(v);
}

// function to print adjacency list
void printGraph(vector<int> adj[], int nodes) {
	for (int u = 0; u < nodes; u++) {
		cout << "Node " << u << " is connected with " << " \n head ";
		for (auto x : adj[u])
			cout << " -> " << x;
		cout << ln;
	}
}

void BFS(vector<int> adj[], int s, int nodes) {
	// Mark all the vertices as not visited
	vector<bool> visited(nodes);
	fill(visited.begin(), visited.end(), false);

	// create a queue for BFS
	queue<int> q;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	q.push(s);

	// 'i' will be used to get all adjacent vertices of a vertex
	vector<int>::iterator i;
	while (not q.empty()) {
		s = q.front();
		cout << s << " ";
		q.pop();

		// Get all adjacent vertices of the dequeued vertex s. If a adjacent has not been visited, then mark it visited and enqueue it.
		for (i = adj[s].begin(); i != adj[s].end(); i++) {
			if (not visited[*i]) {
				visited[*i] = true;
				q.push(*i);
			}
		}
	}
}


int main() {
	int nodes = 4;
	vector<int> adj[nodes + 1];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 0);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 3);
	printGraph(adj, nodes);
	cout << ln << ln;
	cout << "The following is Breadth First Traversal (starting from vertex 2) \n" << ln;
	BFS(adj, 2, 4);
	return 0;
}