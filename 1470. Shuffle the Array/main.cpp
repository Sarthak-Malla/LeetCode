#include <bits/stdc++.h>
using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {
	vector<int> ans;
	int i = 0;
	for (int j = nums.size()/2; j < nums.size(); j++) {
		ans.push_back(nums[i]);
		ans.push_back(nums[j]);

		i++;
	}

	return ans;
}

int main(){
	vector<int> nums = {2,5,1,3,4,7};
	int n = 3;

	vector<int> ans = shuffle(nums, n);
	
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}