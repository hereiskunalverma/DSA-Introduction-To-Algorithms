/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-12 08:53:24  (IST)
*/



// Important - Backedge (the edge with which we have visited the other nodes and taking back to the intial node)


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
	void addEdge(int i, int j, bool undir = false) {
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

	bool dfs(int node, vector<bool> &visited, vector<bool> &stack) {
		// return true if backedge found
		visited[node] = true;
		stack[node] = true;
		for (int nbr : l[node]) {
			if (stack[nbr] == true) { // immediately find backedge
				return true;
			}
			else if (visited[nbr] == false) { // recursively finds the backedge
				bool nbrFoundCycle = dfs(nbr, visited, stack);
				if (nbrFoundCycle)
					return true;
			}
		}
		stack[node] = false;
		return false;
	}
	bool contains_cycle() {
		vector<bool> visited(V, false);
		vector<bool> stack(V, false);
		for (int i = 0; i < V; i++) {
			if (not visited[i]) {
				if (dfs(i, visited, stack))
					return true;
			}
		}
		return false;
	}
};
int main()
{
	Graph g(3);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	cout << g.contains_cycle() << ln;
	return 0;
}
