#include<bits/stdc++.h>
using namespace std;
void max_heapify(int *a, int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && a[j + 1] > a[j])
            j = j + 1;
        if (temp > a[j])
            break;
        else if (temp <= a[j])
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
    return;
}
void build_maxheap(int *a, int n)
{
    int i;
    for (i = n / 2; i >= 1; i--)
    {
        max_heapify(a, i, n);
    }
}
int main()
{
    int n, i, x;
    int a[20] = {0, 5, 9, 6, 7, 1, 3, 8};
    n = 7;
    build_maxheap(a, n);
    cout << "Max Heap\n";
    for (i = 1; i <= n; i++)
    {
        cout << a[i] << endl;
    }
}