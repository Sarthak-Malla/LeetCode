#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> left(1, 1);
    vector<int> right(1, 1);
    int lpro = 1, rpro = 1;
    vector<int> ans;
    
    for (int i = 1; i < nums.size(); i++) {
        lpro *= nums[i - 1];
        left.push_back(lpro);
    }
    
    for (int i = nums.size() - 1; i >= 0; i--) {
        rpro *= nums[i];
        right.push_back(rpro);
    }
    
    for (int i = 1; i <= nums.size(); i++) {
        ans.push_back(left[i - 1] * right[nums.size() - i]);
    }
    
    return ans;
}

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);

    vector<int> ans = productExceptSelf(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<endl;
    }

    return 0;
}