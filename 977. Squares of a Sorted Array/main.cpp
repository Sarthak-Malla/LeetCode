#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> ans;
    int i = 0;
    while (i < nums.size() && nums[i] < 0)
        i++;

    int left = i-1, right = i;

    while (left >= 0 && right < nums.size()) {
        if (pow(nums[left], 2) >= pow(nums[right], 2)) {
            ans.push_back(pow(nums[right], 2));
            right++;
        } else {
            ans.push_back(pow(nums[left], 2));
            left--;
        }
    }

    while (left >= 0) {
        ans.push_back(pow(nums[left], 2));
        left--;
    }
    while (right < nums.size()) {
        ans.push_back(pow(nums[right], 2));
        right++;
    }

    return ans;
}

int main(){
    vector<int> nums;
    nums.push_back(-10);
    nums.push_back(-9);
    // nums.push_back(0);
    // nums.push_back(3);
    // nums.push_back(10);
    // nums.push_back(10);
    // nums.push_back(10);
    // nums.push_back(11);

    vector<int> ans = sortedSquares(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<endl;
    }

    return 0;
}