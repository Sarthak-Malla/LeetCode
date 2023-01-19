#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
	// getting prefix sum
	int psum = 0;
	int res = 0;

	// hash map to store the frequency of the prefix sum such that when we encounter it again, 
	// we know the number of subarrays that can be trimmed from the current subarray such that the sum is divisible by k
	unordered_map<int,int> hash;
	hash[0] = 1;

	int n = nums.size();

	for (int i = 0 ; i < n; i++) {
		// getting the prefix sum
		psum += nums[i];

		// getting the modded value
		int modded = psum % k;

		// if the modded value is negative, we add k to it to make it positive
		if (modded < 0) modded += k;

		// if the modded value is already present in the hash map, 
		// we add the frequency of the modded value to the result since it is the number of ways 
		// we can trim the current subarray such that the sum is divisible by k
		res += hash[modded];

		// we increment the frequency of the modded value in the hash map
		hash[modded]++;
	}

	return res;
}

int main(){
	vector<int> nums = {4,5,0,-2,-3,1};
	int k = 5;
	cout << subarraysDivByK(nums, k) << endl;

	return 0;
}