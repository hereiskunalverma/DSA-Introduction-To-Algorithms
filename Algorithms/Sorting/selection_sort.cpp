#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void selection_sort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int temp = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[temp])
				temp = j;
		}
		swap(&a[temp], &a[i]);
	}
}
int main()
{
	int a[] = {4, 2, 5, 1, 4, 6, 1};
	int n = sizeof(a) / sizeof(int);
	cout << "Array before sort " << ln;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	selection_sort(a, n);
	cout << "\nArray after Selection sort " << ln;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
