#include <bits/stdc++.h>

using namespace std;

int maxOperations(vector<int>& nums, int k) {
	int ans = 0;
	int n = nums.size();
	int l = 0, r = n-1;

	sort(nums.begin(), nums.end());

	while (l < r) {
		int sum = nums[l] + nums[r];
		if (sum == k) {
			l++;
			r--;
			ans++;
		} else if (sum > k)
			r--;
		else
			l++;
	}

	return ans;
}

int main(){
	vector<int> nums = {1,2,3,4};
	int k = 5;

	cout << maxOperations(nums, k) << endl;

	return 0;
}