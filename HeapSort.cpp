// C++ program for implementation of Heap Sort Based on Binary Tree
#include <iostream>
using namespace std;
#define printArray(a,n) for(int i=0; i<n; i++)cout<<a[i]<<" ";


// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
	int largest=i; // largest as root
	int left=2*i+1; // left = 2*i + 1
	int right = 2*i+2; // right = 2*i + 2

	// if left child is larger than root
	if (left<n && arr[left]>arr[largest])
		largest=left;
	// if right child is larger than largest
	if (right<n && arr[right]>arr[largest])
		largest=right;
	// if largest is not root
	if (largest!=i){
		swap(arr[i], arr[largest]);
		// recursively heapify the affected sub - tree
		heapify(arr, n, largest);
	}

}

// funtion for heap sort
void heapSort(int arr[], int n)
{
	// build heap (rearrange array)
	for (int i=n/2-1; i>=0; i--)
		heapify(arr, n,i);
	// one by one extract an element from heap
	for(int i=n-1; i>0; i--){
		// move current root to end
		swap(arr[0], arr[i]);
		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	cout << "Sorted array is \n";
	printArray(arr, n);
}