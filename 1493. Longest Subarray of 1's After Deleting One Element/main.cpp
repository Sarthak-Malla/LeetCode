#include <bits/stdc++.h>

using namespace std;

int longestSubarray(vector<int>& nums) {
	int n = nums.size(), l = 0, r = 0;
	int curr = 0, max_ = 0;

	int idx = 0, all_ones = 1, n_zero = 0;

	while (r < n) {
		if (nums[r] == 1)
			curr++;
		else if (nums[r] == 0) {
			if (n_zero == 0) {
				n_zero++;
			} else {
				l = idx + 1;
				curr = r - l;
			}

			idx = r;
			all_ones = 0;
		}
		max_ = max(max_, curr);
		r++;
	}

	if (all_ones)
		max_--;

	return max_;
}

int main(){
	vector<int> nums = {1,1,0,1};
	cout << longestSubarray(nums) << endl;

	return 0;
}