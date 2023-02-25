#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums, int target) {
	int l = 0, r = nums.size();
	while (l < r) {
		int mid = (l + r)/2;
		if (nums[mid] < target)
			l = mid + 1;
		else
			r = mid;
	}

	return l;
}
vector<int> searchRange(vector<int>& nums, int target) {
	// gets the index of the leftmost target
	int l = binarySearch(nums, target);

	// if the target does not exist
	if (l == nums.size() || nums[l] != target)
		return {-1, -1};

	// gets the index of leftmost target + 1
	int r = binarySearch(nums, target + 1);

	return {l, r - 1};
}

int main(){
	vector<int> nums = {5, 7, 7, 8, 8, 10};
	int target = 8;
	vector<int> ans = searchRange(nums, target);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}