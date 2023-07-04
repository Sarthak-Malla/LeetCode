#include <bits/stdc++.h>

using namespace std;

int singleNumber(vector<int>& nums) {
	int n = nums.size();
	if (n < 2)
		return nums[0];
	
	unordered_map<int, int> hash;
	for (int i = 0; i < n; i++)
		hash[nums[i]]++;
	
	for (auto i = hash.begin(); i != hash.end(); i++)
		if (i->second == 1)
			return i->first;
		
	return 0;
}

int main(){
	vector<int> nums = {4, 1, 2, 1, 2};
	cout << singleNumber(nums) << endl;

	return 0;
}