/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-12 13:37:08  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

class node
{
public:
	int x;
	int y;
	int dist;
	node(int x, int y, int dist) {
		this->x = x;
		this->y = y;
		this->dist = dist;
	}
};

class Compare
{
public:
	bool operator()(const node &a, const node &b) {
		return a.dist <= b.dist;
	}
};


int shortest_path(vector<vector<int>> grid) {
	// return the shortest path len
	int m = grid.size();
	int n = grid[0].size();
	int i = 0;
	int j = 0;
	vector<vector<int>> dist(m + 1, vector<int>(n + 1, INT_MAX));
	dist[i][j] = grid[0][0];
	set<node, Compare> s;
	s.insert(node(0, 0, dist[0][0]));
	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};
	while (not s.empty()) {
		auto it = s.begin();
		int cx = it->x;
		int cy = it->y;
		int cd = it->dist;
		s.erase(it);
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx >= 0 and nx<m and ny >= 0 and ny < n and cd + grid[nx][ny] < dist[nx][ny]) {
				node temp(nx, ny, dist[nx][ny]);
				int nd = grid[nx][nx] + cd;
				dist[nx][ny] = nd;
				s.insert(node(nx, ny, nd));
			}
		}
	}
	return dist[m - 1][n - 1];
}


int main()
{

}
