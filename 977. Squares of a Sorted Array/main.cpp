#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> left;
    vector<int> right;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 0)
            left.insert(left.begin(), nums[i]);
        else 
            right.push_back(nums[i]);
    }

    int l = 0, r = 0, a = 0;
    while (l < left.size() && r < right.size()) {
        if (pow(left[l], 2) > pow(right[r], 2) ) {
            ans.push_back(pow(right[r], 2)); // 0 9 
            a++; // 1 2
            r++; // 1 2
        } else {
            ans.push_back(pow(left[l], 2));
            a++;
            l++;
        }
    }

    while (l < left.size()) {
        ans.push_back(pow(left[l], 2));
        a++;
        l++;
    }
    while (r < right.size()) {
        ans.push_back(pow(right[r], 2));
        a++;
        r++;
    }

    return ans;
}

int main(){
    vector<int> nums;
    nums.push_back(-10);
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(10);

    vector<int> ans = sortedSquares(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<endl;
    }

    return 0;
}