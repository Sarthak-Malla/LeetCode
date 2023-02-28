#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
	int n = nums.size();
	if (n < 2)
		return nums[0];
	vector<int> dp(n, INT_MIN);
	dp[0] = nums[0];
	dp[1] = nums[1];

	for (int i = 2; i < n; i++)
		for (int j = 0; j < i-1; j++)
			dp[i] = max({dp[i], dp[j] + nums[i], dp[i-1]});

	return max(dp[n-1], dp[n-2]);
}

int main(){
	vector<int> nums = {2, 3, 2};
	cout << rob(nums) << endl;

	return 0;
}