#include <bits/stdc++.h>

using namespace std;

int helper(vector<int>& nums, int l, int r, int target) {
    if (l <= r) {
        int m = (l+r)/2;
        if (nums[m] == target)
            return m;
        else if (nums[m] < target)
            return helper(nums, m+1, r, target);
        else
            return helper(nums, l, m-1, target);
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    return helper(nums, 0, nums.size()-1, target);
}

int main(){
	vector<int> nums = {-1,0,3,5,9,12};
	int target = 9;

	cout << search(nums, target) << endl;

	return 0;
}