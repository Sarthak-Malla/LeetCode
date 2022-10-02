#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int ans = 0;
    int s = nums.size();

    for (int i = 0; i < s; i++) {
        ans += nums[i];
    }

    int sum_to_n = (s*(s+1))/2;

    return sum_to_n - ans;
}

int main(){
    vector<int> nums = {0,1,3};
    cout << missingNumber(nums) << endl;

    return 0;
}