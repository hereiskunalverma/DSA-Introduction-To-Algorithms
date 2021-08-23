/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-11 13:59:11  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;



class Graph {
	int V; // nodes/vertices
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
		// Iterate over all rows
		for (int i = 0; i < V; i++) {
			cout << i << "-->";
			for (auto node : l[i]) {
				cout << node << ",";
			}
			cout << ln;
		}
	}
};


int main()
{
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(2, 1);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.printAdjList();
	return 0;

}
