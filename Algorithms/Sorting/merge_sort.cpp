// C++ program for Merge Sort (Divide-Conquer Based)
// Based on implementation in "Introduction To Algorithms Chapter 2"

/*
Pseudo Code is as follows --> 

Steps->

I. MergeSort Function

0. if p(initial index of array)<r(last index of array)
1. set q = (p+r)/2
2. Call MergeSort for first halve of the array (arr, p, q)
3. Again Call MergeSort for second halve of the array with (arr, q+1, r)
4. Finally Call Merge to get the sorted array with (arr, p, q, r)


II. Merge Function

0. Create two arrays as L[0...n1] and R[0...n2], where n1, and n2 are defined below
1. Divide the array in two sequences based on a index (usually middle) q
2. Assign last element of both the array as Infinity
3. Initialize two variable as i and j equals 0
4. Iterate with a new variable k from range p(initial index of original array) and r (last index of original array)
5. Following the previous step, check the smaller element in two array and add that to the original array
6. Bingo! We got the Merge Sort Algorithm


mergeSort(arr,p,r){
	if(p<r)
		q=(p+r)/2
		mergeSort(arr,p,q)
		mergeSort(arr,q+1,r)
		merge(arr,p,q,r)
}


merge(arr, p, q, r){
	n1 = q-p+1
	n2 = r-q
	Let L[0...n1] and R[0...n2]
	for i to n1
		L[i]=arr[p+i]
	for j to n2
		R[j]=arr[q+j+1]
	L[n1]=Infinity
	R[n2]=Infinity
	i=0
	j=0
	for k from p to r
		if L[i]<=R[j]
			arr[k]=L[i]
			i=i+1
		else
			arr[k]=R[j]
			j=j+1
}
*/



#include <iostream>
using namespace std;


void merge(int arr[], int p, int q, int r){
	int n1=q-p+1;
	int n2=r-q;
	int L[n1], R[n2];
	for (int i =0; i<n1; i++)
		L[i]=arr[p+i];
	for (int j = 0; j<n2; j++)
		R[j]=arr[q+j+1];
	L[n1]=INT_MAX;
	R[n2]=INT_MAX;

	int i = 0;
	int j = 0;
	for(int k = p; k<=r; k++){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}
		else{
			arr[k]=R[j];
			j++;
		}
	}
}
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[],int p,int r){
	if (p<r){
		int q=(p+r)/2;
		mergeSort(arr, p, q);
		mergeSort(arr, q+1, r);
		merge(arr,p,q,r);
	}
}


// Function to print an array
void printArray(int A[], int size)
{
	for(int i=0; i<size; i++){
		cout<<A[i]<<" ";
	}
}

// Driver code
int main()
{
	int arr[] = { 12, 13, 11, 5, 6, 7 };
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	cout<<"Given array is\n";
	printArray(arr, arr_size);
	mergeSort(arr, 0, arr_size-1);

	cout<<"\nSorted Array is \n";
	printArray(arr, arr_size);
	return 0;
}

