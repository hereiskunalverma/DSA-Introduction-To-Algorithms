/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-11 14:07:59  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

class node {
public:
	string name;
	list<string> nbrs;
	node(string name) {
		this->name = name;
	}
};

class Graph
{
	unordered_map<string, node*> m;
public:
	Graph(vector<string> cities) {
		for (auto city : cities) {
			m[city] = new node(city);
		}
	}


	void addEdge(string x, string y, bool undir = false) {
		m[x]->nbrs.push_back(y);
		if (undir)
			m[y]->nbrs.push_back(x);
	}

	void printAdjList() {
		for (auto cityPair : m) {
			auto city = cityPair.first;
			node* n = cityPair.second;
			cout << city << " -> ";
			for (auto nbr : n->nbrs) {
				cout << nbr << ",";
			}
			cout << ln;
		}
	}
};


int main()
{
	vector<string> cities = {"Delhi", "London", "Paris", "New York"};
	Graph g(cities);
	g.addEdge("Delhi", "London");
	g.addEdge("New York", "London");
	g.addEdge("Delhi", "Paris");
	g.addEdge("Paris", "New York");
	g.printAdjList();
	return 0;

}
