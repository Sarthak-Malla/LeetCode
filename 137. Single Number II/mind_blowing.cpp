#include <bits/stdc++.h>

using namespace std;

int singleNumber(vector<int>& nums) {
    // ones stores all the bits that have appeared once
    // twos stores all the bits that have appeared twice
    // when a bit appears for the third time, it is removed from both
    int ones = 0, twos = 0;

    // for each number in nums
    // first appearance:
    // add it to ones
    // don't add it to twos because it has not appeared twice yet
    // second appearance:
    // remove it from ones
    // add it to twos because it has appeared twice
    for (int num : nums) {
        ones = (ones ^ num) & ~twos;
        twos = (twos ^ num) & ~ones;
    }

    return ones;
}

int main(){
	vector<int> nums = {4, 1, 2, 1, 2};
	cout << singleNumber(nums) << endl;

	return 0;
}