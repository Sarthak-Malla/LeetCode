#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    vector<int> sums;
    int s = 0;
    for (int i = 0; i < nums.size(); i++) {
        s += nums[i];
        sums.push_back(s);
    }
    
    int min = sums[0];
    int max = sums[0];
    for (int i = 1; i < sums.size(); i++) {
        if (max < sums[i]) 
            max = sums[i];
        
        if (sums[i] - min > max)
            max = sums[i] - min;
        
        if (sums[i] < min)
            min = sums[i];
    }
    
    return max;
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