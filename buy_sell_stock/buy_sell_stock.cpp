// buy and sell stock atmost once

#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(const std::vector<int> &v) {
	int n = v.size();
	int diff[n-1];

	for(int i=0;i<n-1;i++)
		diff[i] = v[i+1]-v[i];

	int curr_max = diff[0];
	int max_so_far = diff[0];

	for(int i=0;i<n-1;i++) {
		curr_max = max(diff[i], curr_max+diff[i]);
		max_so_far = max(max_so_far, curr_max);
	}
	return (max_so_far>0)?max_so_far:0;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<char> v(n);

	for(int i=0;i<n;i++)
		std::cin >> v[i];

	std::cout << maxProfit(v) << endl;
	return 0;
}