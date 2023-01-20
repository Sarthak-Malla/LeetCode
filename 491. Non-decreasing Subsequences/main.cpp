#include <bits/stdc++.h>
using namespace std;

int n;
set<vector<int>> hash;
void backTracking(vector<int>& cur, vector<int>& nums, int start) {
	// base case
	if (cur.size() > 1)
		hash.insert(cur);
	
	// if cur is empty then we take the last element as -200
	int last = -200;
	if (!cur.empty())
		// taking last element of cur
		last = cur[cur.size() - 1];

	// looks at every element after start
	for (int i = start; i < n; i++) {
		if (nums[i] >= last)  {
			cur.push_back(nums[i]);

			// recursive call
			backTracking(cur, nums, i+1);

			// removing the last element
			cur.pop_back();
		}
	}
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
	n = nums.size();
	vector<int> temp = {};

	backTracking(temp, nums, 0);

	// changing set to vector
	vector<vector<int>> ans;
	for (auto x : hash)
		ans.push_back(x);

	return ans;
}

int main(){

	return 0;
}