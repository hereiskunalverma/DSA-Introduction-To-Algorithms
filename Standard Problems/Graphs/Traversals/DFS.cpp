/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-11 14:51:53  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;


class Graph
{
	int V;
	list<int> *l;
public:
	Graph(int v) {
		V = v;
		l = new list<int>[V];
	}
	void addEdge(int i, int j, bool undir = true) {
		l[i].push_back(j);
		if (undir)
			l[j].push_back(i);
	}
	void dfsHelper(int node, bool *visited) {
		visited[node] = true;
		cout << node << ",";
		// make a dfs call on all its unvisited neighbors;
		for (int nbr : l[node]) {
			if (not visited[nbr]) {
				dfsHelper(nbr, visited);
			}
		}
		return;
	}
	void dfs(int source) {
		bool *visited = new bool[V] {0};
		dfsHelper(source, visited);

	}
	void printAdjList() {
		for (int i = 0; i < V; i++) {
			cout << i << " -> ";
			for (auto n : l[i])
				cout << n << ",";
			cout << ln;
		}
	}

};


int main()
{
	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.addEdge(5, 6);
	g.addEdge(4, 5);
	g.addEdge(0, 4);
	g.addEdge(3, 4);
	g.dfs(1);
	return 0;
}
