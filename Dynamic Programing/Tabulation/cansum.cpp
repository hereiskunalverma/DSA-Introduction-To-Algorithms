#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
string cansum(int target, vector<int> numbers){
	vector<bool> table(target+1);
	fill(table.begin(), table.end(), false);
	table[0]=true;
	for(int i=0;i<=target;i++){
		if(table[i]==true){
			for(auto a:numbers){
				table[i+a]=true;
			}
		}
	}
	if (table[target])
		return "true";
	else
		return "false";
}
int main()
{
  vector<int> a1={2,3};
  vector<int> a2={5,3,4,7};
  vector<int> a3={2,4};
  vector<int> a4={2,3,5};
  vector<int> a5={7,14};
  cout<<cansum(7,a1)<<ln;
  cout<<cansum(7,a2)<<ln;
  cout<<cansum(7,a3)<<ln;
  cout<<cansum(8,a4)<<ln;
  cout<<cansum(300,a5)<<ln;
}

