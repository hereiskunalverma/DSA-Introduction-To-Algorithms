/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-06-16 09:01:53  (IST)
*/

/*

Below is the implementation of UNDIRECTED/UNWEIGHTED GRAPH WITH 5 VERTICES

https://cdncontribute.geeksforgeeks.org/wp-content/uploads/undirectedgraph.png

*/


#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

// Function to add an edge in an undiredted graph

void addEdge(vector<int> adjList[], int n1, int n2) {
	// repeat it because it is an undirected graph
	adjList[n1].push_back(n2);
	adjList[n2].push_back(n1);
}
// Function to print the adjacency list representation of graph
void printGraph(vector<int> adjList[], int nodes) {
	for (int i = 0; i < nodes; i++) {
		cout << "\n Adjacency List of vertext : " << i << "\nHead ";
		for (auto val : adjList[i])
			cout << "->" << val;
		cout << ln;
	}
}
int main()
{
	int nodes = 5;
	vector<int> adjList[nodes];
	addEdge(adjList, 0, 1);
	addEdge(adjList, 0, 4);
	addEdge(adjList, 1, 2);
	addEdge(adjList, 1, 3);
	addEdge(adjList, 1, 4);
	addEdge(adjList, 2, 3);
	addEdge(adjList, 3, 4);
	printGraph(adjList, nodes);
}


