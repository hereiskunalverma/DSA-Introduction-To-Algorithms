#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

ll fib(int n){
	vector<ll> table(n+1);
	table[0]=0;
	table[1]=1;
	for(int i=2; i<=n; i++){
		table[i]=table[i-1]+table[i-2];
	}
	return table[n];

}
int main()
{
	cout<<fib(6)<<ln;
	cout<<fib(7)<<ln;
	cout<<fib(8)<<ln;
	cout<<fib(50)<<ln;
	return 0;
}
