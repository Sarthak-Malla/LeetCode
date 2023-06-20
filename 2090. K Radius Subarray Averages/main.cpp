#include <bits/stdc++.h>

using namespace std;

vector<int> getAverages(vector<int>& nums, int k) {
	int n = nums.size();
	int left = 0;
	int right = k;
	long sum = 0;

	// some base cases
	if (k == 0) return nums;

	// this condition checks if any of the index lies within the range
	if (2*k >= n) {
		vector<int> res(n, -1);
		return res;
	}

	// initializing with k number of -1, because the first k elements cannot have averages
	vector<int> ans(k, -1);
	for (int i = 0; i < n; i++) {
		sum += nums[i];
		// start taking average once our window fits into the array
		if (i >= 2*k) {
			ans.push_back(sum / (2*k + 1));
			sum -= nums[left];
			left++;
		}
	}

	// the last k number of -1
	for (int i = 0; i < k; i++) {
		ans.push_back(-1);
	}

	return ans;
}

int main(){
	vector<int> nums = {1, 3, 2, 6, -1, 4, 1, 8, 2};
	int k = 5;
	vector<int> ans = getAverages(nums, k);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}