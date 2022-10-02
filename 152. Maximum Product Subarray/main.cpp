#include<iostream>
#include<vector>
using namespace std;

int maxProduct(vector<int>& nums) {
    vector<int> sums(nums.size(), 0);
    int left = 0;
    int max = INT_MIN;
    while (left < nums.size()) {
        for (int i = 0; i < sums.size(); i++) {
            if (i == left)
                sums[i] = nums[i];
            
            if (i - 1 >= left)
                sums[i] = sums[i-1] * nums[i];
            
            if (sums[i] > max)
                max = sums[i];
        }

        left++;
    }
    return max;
}

int main(){
    vector<int> nums = {2,3,-2,4};
    cout << maxProduct(nums) << endl;

    return 0;
}