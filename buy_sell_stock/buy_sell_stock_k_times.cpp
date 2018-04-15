// Buy and sell stocks atmost k times

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int maxProfit(int k, const vector <int> prices) {
	int n = prices.size();
	int prof[k+1][n];

	for(int i=0;i<=k;i++) {
		for(int j=0;j<n;j++) {
			if(i==0 || j==0)
				prof[i][j] = 0;
			else {
				int curr_profit = 0;
				for(int m=0;m<j;m++) {
					curr_profit = max(curr_profit, prices[j]-prices[m]+prof[i-1][m]);
				}
				prof[i][j] = max(prof[i][j-1], curr_profit);
			}
		}
	}

	for(int i=0;i<=k;i++) {
		for(int j=0;j<n;j++)
			cout << prof[i][j] << " ";
		cout << endl;
	}
	return prof[k][n-1];
}

int main() {
	freopen("data.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	vector<int> prices(n);

	for(int i=0;i<n;i++)
		cin >> prices[i];
	cout << maxProfit(k, prices) << endl;
	return 0;
}