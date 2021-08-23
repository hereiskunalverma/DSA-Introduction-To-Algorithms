/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-06-18 09:21:43  (IST)
*/



// Fibonnaci Series

#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

int fib(int n) {
	if (n < 2)
		return n;
	else
		return fib(n - 1) + fib(n - 2);
}
int main()
{
	int n = 5;
	for (int i = 0; i < 5; i++) {
		cout << fib(i) << " ";
	}
	cout << ln;

}
