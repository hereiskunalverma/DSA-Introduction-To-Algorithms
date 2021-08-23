/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-11 14:39:59  (IST)
*/




//Shortest Path using BFS (Undiredted Graph)

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
	void bfs(int source, int dest = -1) {
		queue<int> q;
		bool *visited = new bool[V] {0};
		int *dist = new int[V] {0};
		int *parent = new int[V];
		for (int i = 0; i < V; i++)
			parent[i] = -1;
		q.push(source);
		visited[source] = true;
		parent[source] = source;
		dist[source] = 0;
		while (not q.empty()) {
			int f = q.front();
			cout << f << ln;
			q.pop();
			for (auto nbr : l[f]) {
				if (not visited[nbr]) {
					q.push(nbr);
					// parent and dist
					parent[nbr] = f;
					dist[nbr] = dist[f] + 1;
					visited[nbr] = true;
				}
			}
		}
		// print the shortest distance
		for (int i = 0; i < V; i++) {
			cout << "Shortest dist to " << i << " is " << dist[i] << ln;
		}

		// path from source to dest
		if (dest != -1) {
			int temp = dest;
			while (temp != source) {
				cout << temp << " --- ";
				temp = parent[temp];
			}
			cout << source << ln;
		}
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
	g.bfs(1, 6);


}
