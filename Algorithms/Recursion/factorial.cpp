/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-06-18 09:16:10  (IST)
*/


// Factorial

#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
int fact(int n) {
	if (n == 0)
		return 1;
	else
		return n * fact(n - 1);
}
int main()
{
	int n = 5;
	cout << fact(n) << ln;

}
