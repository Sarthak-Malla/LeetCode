#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        ans ^= nums[i];
        ans ^= i;
    }
    ans ^= nums.size();

    return ans;
}

int main(){
    vector<int> nums = {0,1,3};
    cout << missingNumber(nums) << endl;

    return 0;
}