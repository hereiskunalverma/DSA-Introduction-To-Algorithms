/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-12 09:34:41  (IST)
*/



// Weighted Graph


#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;


class Graph
{
	int V;
	list<pair<int, int>> *l;
public:
	Graph(int v) {
		V = v;
		l = new list<pair<int, int>>[V];
	}
	void addEdge(int i, int j, int wt, bool undir = true) {
		l[i].push_back({wt, j});
		if (undir)
			l[j].push_back({wt, i});
	}
	int dijkshtra(int src, int dest) {
		vector<int> dist(V, INT_MAX);
		set<pair<int, int>> s;
		dist[src] = 0;
		s.insert({0, src});
		while (not s.empty()) {
			auto it = s.begin();
			int node = it->second;
			int distTillNow = it->first;
			s.erase(it); // Pop
			// Iterate over the nbrs of node
			for (auto nbrPair : l[node]) {
				int nbr = nbrPair.second;
				int currentEdge = nbrPair.first;
				if (distTillNow + currentEdge < dist[nbr]) {
					// remove if nbr exists with old value
					auto f = s.find({dist[nbr], nbr});
					if (f != s.end()) {
						s.erase(f);
					}
					dist[nbr] = distTillNow + currentEdge;
					s.insert({dist[nbr], nbr});
				}
			}
		}
		// single source shortest dist to all other nodes
		for (int i = 0; i < V; i++) {
			cout << "Node " << i << " Dist " << dist[i] << ln;
		}
		return dist[dest];
	}
};


int main()
{
	Graph g(5);
	g.addEdge(0, 1, 1);
	g.addEdge(1, 2, 1);
	g.addEdge(0, 2, 4);
	g.addEdge(0, 3, 7);
	g.addEdge(3, 2, 2);
	g.addEdge(3, 4, 3);
	cout << g.dijkshtra(0, 4) << ln;
	return 0;
}
