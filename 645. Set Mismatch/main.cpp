#include<iostream>
#include<vector>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    vector<bool> check(nums.size(), false);
    int re;
    for (int i = 0; i < nums.size(); i++) {
        if (i - 1 >= 0 && nums[i] == nums[i-1])
            re = nums[i];
        
        check[nums[i] - 1] = true;
    }

    int missing;
    for (int i = 0; i < check.size(); i++) {
        if (!check[i])
            missing = i+1;
    }

    return {re, missing};
}

int main(){
    vector<int> nums = {1,2,2,4};
    vector<int> ans = findErrorNums(nums);

    cout<<'['<<ans[0]<<", "<<ans[1]<<']'<<endl;

    return 0;
}