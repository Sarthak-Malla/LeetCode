#include <bits/stdc++.h>

using namespace std;

int binary(vector<int>& nums, int l, int r) {
	if (l < r) {
		int m = (l+r)/2;
		if (nums[l] < nums[r])
			return nums[l];
		else {
			if (nums[l] > nums[m])
				return binary(nums, l, m);
			else
				return binary(nums, m+1, r);
		}
	}
	return nums[l];
}
int findMin(vector<int>& nums) {
	return binary(nums, 0, nums.size()-1);
}

int main(){
	vector<int> nums = {4,5,6,7,0,1,2};
	cout << findMin(nums) << endl;

	return 0;
}