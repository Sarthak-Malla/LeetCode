#include <bits/stdc++.h>

using namespace std;

int longestConsecutive(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int n = nums.size();
	if (n == 0) return 0;
	int curr = 1, max_ = 1;
	for (int i = 1; i < n; i++) {
		if (nums[i-1] == nums[i] - 1)
			curr++;
		else if (nums[i-1] == nums[i])
			continue;
		else
			curr = 1;
		max_ = max(max_, curr);
	}

	return max_;
}

int main(){
	vector<int> nums = {100, 4, 200, 1, 3, 2};
	cout << longestConsecutive(nums) << endl;

	return 0;
}