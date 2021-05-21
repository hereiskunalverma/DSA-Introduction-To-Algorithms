 // Ways in a Grid Traveler from top-left to bottom-right moving only down and right


#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

int gt(int m, int n){
	int table[m+1][n+1];
	table[0][0]=0;
	table[1][1]=1;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			int current=table[i][j];
			if(j+1<=n)table[i][j+1]+=current;
			if(i+1<=m)table[i+1][j]+=current;
		}
	}
	return table[m][n];
}


int main()
{
	cout<<gt(1,1)<<ln; // 1
	cout<<gt(2,3)<<ln; // 3
	cout<<gt(3,2)<<ln; // 3
	cout<<gt(3,3)<<ln; // 6
	cout<<gt(18,18)<<ln; // 23336060220
  
}
