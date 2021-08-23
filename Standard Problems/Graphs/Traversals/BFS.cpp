/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-11 14:24:32  (IST)
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
	void bfs(int source) {
		queue<int> q;
		bool *visited = new bool[V] {0};
		q.push(source);
		visited[source] = true;
		while (not q.empty()) {
			int f = q.front();
			cout << f << ln;
			q.pop();
			// push the neighbors of the current node
			for (auto nbr : l[f])
				if (not visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
				}
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
	g.bfs(1);
	return 0;

}
