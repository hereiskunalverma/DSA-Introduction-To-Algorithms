/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-12 08:33:49  (IST)
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

	void printAdjList() {
		for (int i = 0; i < V; i++) {
			cout << i << " -> ";
			for (auto x : l[i])
				cout << x << ",";
			cout << ln;
		}
	}

	bool dfs(int node, vector<bool> &visited, int parent) {
		visited[node] = true;
		for (auto nbr : l[node]) {
			if (not visited[nbr]) {
				bool nbrFoundCycle = dfs(nbr, visited, node);
				if (nbrFoundCycle)
					return true;
			}
			// nbr is visited and its not the parent of current node in the current dfs call
			else if (nbr != parent)
				return true;
		}
		return false;
	}
	bool contain_cycle() {
		// Graph is single component i.e,. no disconnected branches
		vector<bool> visited(V, false);
		return dfs(0, visited, -1);
	}

};


// just another implementation
bool contains_cycle(int V, vector<pair<int, int>> edges) {
	Graph g(V);
	for (auto edge : edges)
		g.addEdge(edge.first, edge.second);
	return g.contain_cycle();
}

int main()
{
	Graph g(3);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	cout << (g.contain_cycle() ? "Yes" : "No") << ln;
	return 0;
}
