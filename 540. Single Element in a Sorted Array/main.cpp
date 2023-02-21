#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
	int n = nums.size();
	for (int i = 0; i < n; i+=2) {
		if (i + 1 >= n)
			break;
		if (nums[i] != nums[i+1])
			return nums[i];
	}

	return nums[n-1];
}

int main(){
	vector<int> nums = {1,1,2,3,3,4,4,8,8};
	cout << singleNonDuplicate(nums) << endl;

	return 0;
}