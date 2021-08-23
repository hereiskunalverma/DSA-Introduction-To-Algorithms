/*
There are N wines in a row. Each year you sell either the leftmost or rightmost wine. The i-th wine has initial price p[i] and price k*p[i] in the k-th year. What is the max possible total profit ?
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define N 1000

int dp[N][N];

// This array stores the "optimal action"
// for each state i, j
int sell[N][N];

// Function to maximize profit
int maxProfitUtil(vector<int> price, int begin,
				int end, int n) {
	if (dp[begin][end] != -1)
		return dp[begin][end];

	int year = n - (end - begin);

	if (begin == end)
		return year * price[begin];

	// x = maximum profit on selling the
	// wine from the front this year
	int x = price[begin] * year +
			maxProfitUtil(price, begin + 1, end, n);

	// y = maximum profit on selling the
	// wine from the end this year
	int y = price[end] * year +
			maxProfitUtil(price, begin, end - 1, n);

	int ans = max(x, y);
	dp[begin][end] = ans;

	if (x >= y)
		sell[begin][end] = 0;
	else
		sell[begin][end] = 1;

	return ans;
}

// Util Function to calculate maxProfit
int maxProfit(vector<int> price, int n) {
	// reseting the dp table
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			dp[i][j] = -1;

	int ans = maxProfitUtil(price, 0, n - 1, n);

	int i = 0, j = n - 1;

	while (i <= j) {
		// sell[i][j]=0 implies selling the
		// wine from beginning will be more
		// profitable in the long run
		if (sell[i][j] == 0) {
			cout << "start ";
			i++;
		} else {
			cout << "end ";
			j--;
		}
	}

	cout << endl;

	return ans;
}

int main() {

	int n; // number of wines
  cin>>n;
  vector<int> a(n);
  for(int i=0; i<n;i++)cin>>a[i]; // price of wines
	int ans = maxProfit(a, n);
  cout<<ans<<"\n";
	return 0;
}
