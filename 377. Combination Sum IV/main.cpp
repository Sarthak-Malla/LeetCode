#include <bits/stdc++.h>
using namespace std;

int combinationSum4(vector<int>& nums, int target) {
	vector<uint> dp(target + 1);
	// for target 0, you have 1 combination of null set
	dp[0] = 1;

	// standard template
	for (int i = 1; i <= target; i++) {
		for (int j = 0; j < nums.size(); j++) {
			if (nums[j] <= i) {
				dp[i] += dp[i - nums[j]];
			}
		}
	}

	return dp[target];
}

int main(){
	vector<int> nums = {1, 2, 3};
	int target = 4;
	cout << combinationSum4(nums, target) << endl;

	return 0;
}