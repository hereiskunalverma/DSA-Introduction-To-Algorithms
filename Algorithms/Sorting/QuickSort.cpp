#include <iostream>
#include <vector>
using namespace std;
#define ll "\n"

int partition(vector<int> &a, int l, int r) {
  int pivot = a[l];
  int j = l;
  for (int i = l + 1; i < r; i++) {
    if (a[i] < pivot) {
      j++;
      swap(a[j], a[i]);
    }
  }
  swap(a[l], a[j]);
  return j;
}
void QuickSort(vector<int> &a, int l, int r) {
  if (l <= r) {
    int m = partition(a, l, r);
    QuickSort(a, l, m - 1);
    QuickSort(a, m + 1, r);
  }
}
int main() {
  vector<int> a = {2, 3, 2, 5, 1, 6};
  QuickSort(a, 0, a.size());
  for (auto i : a)
    cout << i << " ";
  return 0;
}
