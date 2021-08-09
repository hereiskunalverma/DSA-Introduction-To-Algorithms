/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-09 09:11:13  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;


int count_triangles(vector<pair<int, int>> &points) {
	unordered_map<int, int> freq_x;
	unordered_map<int, int> freq_y;

	for (auto p : points) {
		int x = p.first;
		int y = p.second;
		freq_x[x]++;
		freq_y[y]++;
	}
	int count = 0;
	for (auto p : points) {
		int x = p.first;
		int y = p.second;
		int fx = freq_x[x];
		int fy = freq_y[y];
		if (fx >= 1 and fy >= 1) {
			count += (fx - 1) * (fy - 1);
		}
	}
	return count;
}


int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> points;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		points.push_back({x, y});
	}
	cout << count_triangles(points) << ln;
}
