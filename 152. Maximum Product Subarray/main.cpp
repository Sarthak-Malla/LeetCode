#include<iostream>
#include<vector>
using namespace std;

int maxProduct(vector<int>& nums) {
    int maxNeg = nums[0];
    int maxPos = nums[0];
    int ans = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0)
            swap(maxPos, maxNeg);
        
        maxPos = max(maxPos * nums[i], nums[i]);
        maxNeg = min(maxNeg * nums[i], nums[i]);

        ans = max(ans, maxPos);
    }

    return ans;
}


int main(){
    vector<int> nums = {2,3,-2,4};
    cout << maxProduct(nums) << endl;

    return 0;
}