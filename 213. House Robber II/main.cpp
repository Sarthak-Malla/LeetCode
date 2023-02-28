#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
	int n = nums.size();
	if (n < 2)
		return nums[0];
	if (n < 3)
		return max(nums[0], nums[1]);
	vector<int> nums2(n-1);
	for (int i = 1; i < n; i++)
		nums2[i-1] = nums[i];
	
	n--;
	vector<int> dp1(n, INT_MIN);
	vector<int> dp2(n, INT_MIN);

	// house robber on [0, n-1]
	dp1[0] = nums[0];
	dp1[1] = nums[1];
	for (int i = 2; i < n; i++)
		for (int j = 0; j < i - 1; j++)
			dp1[i] = max({dp1[i], dp1[j] + nums[i], dp1[i-1]});

	// house robber on [1, n]
	dp2[0] = nums2[0];
	dp2[1] = nums2[1];
	for (int i = 2; i < n; i++)
		for (int j = 0; j < i - 1; j++)
			dp2[i] = max({dp2[i], dp2[j] + nums2[i], dp2[i-1]});
	
	// max of both house robbers
	return max({dp1[n-1], dp2[n-1], dp1[n-2], dp2[n-2]});
}

int main(){
	vector<int> nums = {2,3,2};
	cout << rob(nums) << endl;

	return 0;
}