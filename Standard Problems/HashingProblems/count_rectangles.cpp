/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-09 08:57:04  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

class Point {
public:
	int x, y;
	Point() {

	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};


class Compare {
public:
	bool operator()(const Point p1, const Point p2) {
		if (p1.x == p2.x)
			return p1.y < p2.y;
		return p1.x < p2.x;
	}
};

int count_rectangles(vector<Point> points) {
	// Insert all points in set;
	set<Point, Compare> s; // logn lookup
	for (Point p : points)
		s.insert(p);
	int ans = 0;
	for (auto it = s.begin(); it != prev(s.end()); it++) {
		for (auto jt = next(it); jt != s.end(); jt++) {
			Point p1 = *it;
			Point p2 = *jt;
			// check if not on same axis, p1:p2
			if (p2.x == p1.x or p2.y == p1.y)
				continue;
			// p3, p4
			Point p3(p1.x, p2.y);
			Point p4(p2.x, p1.y);
			if (s.find(p3) != s.end() and s.find(p4) != s.end())
				ans++;
		}
	}
	return ans / 2;
}

int main()
{
	/*
	Input:
	8
	4 1
	4 0
	0 0
	0 1
	1 1
	1 0
	2 0
	2 1
	*/
	int n;
	cin >> n;
	int x, y;
	vector<Point> points;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		Point p(x, y);
		points.push_back(p);
	}
	cout << count_rectangles(points) << ln; // 6

}
