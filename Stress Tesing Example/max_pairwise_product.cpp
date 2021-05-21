#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#define ln "\n"

using namespace std;
long long MaxPairwiseProductNaive(vector<int>& a){
	long long res=0;
	for (int i=0; i<a.size(); i++){
		for (int j=i+1; j<a.size(); j++){
			res = ((res<a[i]*a[j]?a[i]*a[j]:res));
	}
	}
	return res;
}
long long MaxPairwiseProductFast(vector<int>& a){
	int maxind1=0;
	for(int i=0; i<a.size(); i++){
		if (a[i]>a[maxind1]){
			maxind1=i;
		}
	}
	int maxind2=0;
	for(int i=0; i<a.size(); i++){
		if ((a[maxind1]!=a[i]) && (maxind2==-1 || a[i]>a[maxind2])){
			maxind2=i;
		}
	}
	long long res=a[maxind1]*a[maxind2];
	return res;
}
long long MaxPairwiseProductMostEff(vector<int>& a, int n){
	sort(a.begin(), a.end());
	long long res=a[n]*a[n-1];
	return res;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	#endif
	/////////////////////
	// Stress Testing //
	////////////////////
	/*
	while(true){
		int n=rand()%10+2; // number between 0 and 9
		cout<<n<<ln;
		std::vector<int> a;
		for(int i=0; i<n; i++){
			a.push_back(rand()%100000);
		}
		for (int i= 0; i<n; i++)
			cout<<a[i]<<" ";
		cout<<ln;
		long long res1=MaxPairwiseProductNaive(a);
		long long res2=MaxPairwiseProductFast(a); // change funtion to perform stress
		if (res1!=res2){
			cout<<"Wrong Answer"<<res1<<" "<<res2<<ln;
			break;
		}
		else
			cout<<"OK"<<ln;
	}
	*/
	int n;cin>>n;
	vector<int> a(n);
	for(int &x:a)
		cin>>x;
	//cout<<MaxPairwiseProductNaive(a)<<ln; // Naive Algorithm
	//cout<<MaxPairwiseProductFast(a)<<ln; // Fast Algorithm
	cout<<MaxPairwiseProductMostEff(a,n-1)<<ln; // Most Efficient
}
