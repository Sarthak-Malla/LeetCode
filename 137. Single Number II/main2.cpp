#include <bits/stdc++.h>

using namespace std;

int singleNumber(vector<int>& nums) {
	int ans = 0;

    for (int i = 0; i < 32; i++) {
        int sum = 0;
        for (int num : nums)
            sum += (num >> i) & 1;
        
        sum %= 3;
        ans |= (sum << i);
    }

    return ans;
}

int main(){
	vector<int> nums = {4, 1, 2, 1, 2};
	cout << singleNumber(nums) << endl;

	return 0;
}