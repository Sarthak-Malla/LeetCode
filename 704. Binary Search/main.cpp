#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target) {
	int n = nums.size();
	int l = 0, r = n - 1;

	while (l <= r) {
		int m = (l+r)/2;
		if (nums[m] == target) 
			return m;
		else if (target < nums[m])
			r = m-1;
		else
			l = m+1;
	}

	return -1;
}

int main(){
	vector<int> nums = {-1,0,3,5,9,12};
	int target = 9;

	cout << search(nums, target) << endl;

	return 0;
}