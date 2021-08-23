/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-06-22 12:58:53  (IST)
*/

#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

// Depth First Search  - starting from a given node


// Below is the implementation of the image .... https://media.geeksforgeeks.org/wp-content/uploads/20200507075041/ezgif.com-gif-maker7.gif


// We are using a Directed - UnWeighted Graph using adjacency list

#include<bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	list<int>* adjlist;
public:
	Graph(int no_of_nodes)
	{
		this->V = no_of_nodes;
		adjlist = new list<int>[V];
	}
	void addEdge(int start, int finish)
	{
		adjlist[start].push_back(finish);
	}
	void DFSUtil(int the_vertex_to_begin_from, bool if_visited_array[])
	{
		cout << the_vertex_to_begin_from << " ";
		if_visited_array[the_vertex_to_begin_from] = true;
		list<int>::iterator i;
		for (i = adjlist[the_vertex_to_begin_from].begin(); i != adjlist[the_vertex_to_begin_from].end(); i++)
		{
			if (!if_visited_array[*i])
			{
				DFSUtil(*i, if_visited_array);
			}
		}
	}
	void DFS(int start_vertex)
	{
		bool* if_visited = new bool[V];
		for (int i = 0; i < V; i++)
		{
			if_visited[i] = false;
		}
		DFSUtil(start_vertex, if_visited);
	}

};
//DIRECTED GRAPH
//Limitations of Code:- Data should start from 0 and be consistent(0,1,2,3,4 etc)

int main()
{
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(1, 4);
	g.addEdge(1, 3);
	g.addEdge(4, 3);
	g.addEdge(3, 2);
	g.addEdge(2, 2);

	g.DFS(0);
}
