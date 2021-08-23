
#include<iostream>
using namespace std;


// A Divide and Conquer based program for maximum subarray sum problem 
#include <stdio.h> 
#include <limits.h> 


int max(int a, int b) { return (a > b)? a : b; } 

int max(int a, int b, int c) { return max(max(a, b), c); } 



int findMaxCrossSubArray(int a[], int low, int mid, int high){
	int left_sum=INT_MIN;
	int sum=0;
	for (int i =mid; i>=low; i--){
		sum=sum+a[i];
		if (sum>left_sum)
			left_sum=sum;
	}
	int right_sum=INT_MIN;
	sum=0;
	for (int j = mid+1; j<=high; j++){
		sum=sum+a[j];
		if (sum>right_sum){
			right_sum=sum;
		}
	}
	return max(left_sum+right_sum, left_sum, right_sum);
}

int FindMaxSubArray(int a[], int low, int high){
	if (high==low){
		return a[low];
	}
	int mid=(low+high)/2;
	return max(
				FindMaxSubArray(a,low,mid),
				FindMaxSubArray(a,mid+1,high),
				findMaxCrossSubArray(a,low,mid,high)

		);
}


int main(){
	int a[]={2,3,4,5,7};
	int n=sizeof(a)/sizeof(a[0]);
	int max_sum=FindMaxSubArray(a,0,n-1);
	cout<<max_sum<<endl;
	return 0;
}