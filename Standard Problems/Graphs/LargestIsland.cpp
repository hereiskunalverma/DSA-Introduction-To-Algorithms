/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-12 13:50:35  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;


int dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int i, int j, int m, int n) {
	visited[i][j] = true;
	int cs = 1;
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};
	for (int k = 0; k < 4; k++) {
		int nx = i + dx[k];
		int ny = j + dy[k];
		if (nx >= 0 and nx<m and ny >= 0 and ny < n and matrix[nx][ny] == 1 and !visited[nx][ny]) {
			int subcomponent = dfs(matrix, visited, nx, ny, m, n);
			cs += subcomponent;
		}
	}
	return  cs;
}


int largest_island(vector<vector<int>> matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	int largest = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (not visited[i][j] and matrix[i][j] == 1) {
				int size = dfs(matrix, visited, i, j, m, n);
				if (size > largest)
					largest = size;
			}
		}
	}
	return largest;
}


// finding the largest number of 1 in a group


int main()
{
	vector<vector<int>> grid = {
		{1, 0, 0, 1, 0},
		{1, 0, 1, 0, 0},
		{0, 0, 1, 0, 1},
		{1, 0, 1, 1, 1},
		{1, 0, 1, 1, 0}
	};
	cout << largest_island(grid) << ln;

}
