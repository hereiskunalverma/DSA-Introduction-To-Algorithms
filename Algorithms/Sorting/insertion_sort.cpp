/*
Based on pseudo code in the book, Introduction to Algorithms.

Pseudo code -->

for j = 2 to A.length 				// loop through the second element as key in the array
	key = A[j]						// key to compare
	// Insert A[j] into the sorted sequence A[1...j-1]
	i = j-1 						// to compare with the previous element
	while i>0 and A[i]>key 			// to check all the elements before the key if greater than key they are replaced
		A[i+1] = A[i] 				// replace if larger than key
		i = i-1 					// decrement i to check previous element
	A[i+1] = key 					// decrement the element in key


*/


#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void insertion_sort(int a[], int n) {
	int i, j, key;
	for (int i = 1; i < n; i++) {
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

int main() {

	int n;
	//n = 8;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	insertion_sort(a, n);
	return 0;
}
