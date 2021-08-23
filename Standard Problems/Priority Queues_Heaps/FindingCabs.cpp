/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-06 09:09:56  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

class Car
{
public:
	string id;
	int x, y;
	Car(string id, int x, int y) {
		this->id = id;
		this->x = x;
		this->y = y;
	}
	int dist() const {
		return x * x + y * y;
	}
};

class CarCompare {
public:
	bool operator()(const Car A, Car B) {
		return A.dist() < B.dist();
	}
};



void printNearestCars(vector<Car> cars, int k) {
	priority_queue<Car, vector<Car>, CarCompare> max_heap(cars.begin(), cars.begin() + k);
	for (int i = k; i < cars.size(); i++) {
		auto car = cars[i];
		if (car.dist() < max_heap.top().dist()) {
			max_heap.pop();
			max_heap.push(car);
		}
	}
	// print all the cars inside
	vector<Car> output;
	while (not max_heap.empty()) {
		// cout << max_heap.top().id << ln;
		output.push_back(max_heap.top());
		max_heap.pop();
	}
	reverse(output.begin(), output.end());
	for (auto car : output) {
		cout << car.id << ln;
	}
}

int main()
{
	int N, K;
	cin >> N >> K;
	string id;
	int x, y;
	vector<Car > cars;
	for (int i = 0; i < N; i++) {
		cin >> id >> x >> y;
		Car car(id, x, y);
		cars.push_back(car);
	}
	printNearestCars(cars, K);
	/*
	// Input:
	5 3
	C1 1 1
	C2 2 1
	C3 3 2
	C4 0 2
	C5 2 3
	// Ouput:




	*/
}
