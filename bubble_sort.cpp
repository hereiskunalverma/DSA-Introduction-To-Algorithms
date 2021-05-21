// Implementation based on pseudo code from "Introduction To Algorithms book"
/*
Pseudo Code ->
Step:
1. iterate through the array to length -1
2. In above loop, iterate through from j = array.length downto i+1
3. Further from above, if A[j]<A[j-1], swap the elements(using swap function here)
4. Voila! We implemented the Bubble Sort Algorithm

Code->

bubble_sort(){
	for i=0 to i=A.length-1
		for j = A.length downto j=i+1
			if A[j]<=A[j-1]
				swap(A[j],A[j-1])
}


*/




#include <iostream>
using namespace std;

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  

void bubble_sort(int arr[], int size){
	for (int i =0; i<size-1; i++){
		for (int j = size-1; j>=i+1; j--){
			if (arr[j]<arr[j-1]){
				swap(&arr[j],&arr[j-1]);
			}
		}
	}

}

void printArray(int arr[], int size){ // just to print the array (optional implementation)
	for (int i = 0; i<size; i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[] = {3,2,1,6,9,7};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<"Given Array --> \n";
	printArray(arr, size);
	bubble_sort(arr, size);
	cout<<"\nSorted Array --> \n";
	printArray(arr, size);

}