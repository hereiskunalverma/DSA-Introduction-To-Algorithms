/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-28 10:37:27  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;


bool isValid(int mat[][9], int i, int j, int no) {
	// check for row and col
	for (int k = 0; k < 9; k++) {
		if (mat[k][j] == no or mat[i][k] == no)
			return false;
	}
	// check for subgrid
	int sx = (i / 3) * 3;
	int sy = (j / 3) * 3;
	for (int x = sx; x < sx + 3; x++) {
		for (int y = sy; y < sy + 3; y++) {
			if (mat[x][y] == no)
				return false;
		}
	}
	return true;
}

bool solver(int mat[][9], int i, int j, int n) {
	// base case
	if (i == n) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << mat[i][j] << " ";
			}
			cout << ln;
		}

		return true;
	}
	// recursion case
	if (j == n) {
		return solver(mat, i + 1, 0, n);
	}

	// skip the prefilled cell
	if (mat[i][j] != 0) {
		return solver(mat, i, j + 1, n);
	}

	// cell to be filled
	// checking all possibilities
	for (int no = 1; no <= n; no++) {
		// whether it is valid to put number
		if (isValid(mat, i, j, no)) {
			mat[i][j] = no;
			bool solveSub = solver(mat, i, j + 1, n);
			if (solveSub == true)
				return true;
		}
	}
	// if no options works
	mat[i][j] = 0;
	return false;
}


int main()
{

	int n = 9;
	int mat[9][9] = {
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};

	if (not solver(mat, 0, 0, n))
		cout << "No Solution exists!" << ln;



}
