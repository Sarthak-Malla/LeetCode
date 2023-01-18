#include <bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
	int n = nums.size();
	int total_sum = nums[0];
	int local_max = nums[0];
	int local_min = nums[0];
	int tmax = nums[0], tmin = nums[0];

	for (int i = 1; i < n; i++) {
		total_sum += nums[i];

		// kadane for maximum
		local_max = max(nums[i], nums[i] + local_max);
		tmax = max(local_max, tmax);

		// kadane for minimum
		local_min = min(nums[i], nums[i] + local_min);
		tmin = min(local_min, tmin);
	}
	
	if (tmin == total_sum)
		return tmax;

	return max(tmax, total_sum - tmin);
}

int main(){
	vector<int> nums = {5, -3, 5};
	cout<<maxSubarraySumCircular(nums)<<endl;

	return 0;
}