#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int curr = 0;
    int total = INT_MIN;
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        // local maximum is either the current element or the current element plus the previous local maximum
        curr = max(nums[i], curr + nums[i]);
        // global maximum is either the current local maximum or the previous global maximum
        total = max(curr, total);
    }

    return total;
}

int main(){

    vector<int> nums;
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(7);
    nums.push_back(8);

    cout<<maxSubArray(nums)<<endl;

    return 0;
}