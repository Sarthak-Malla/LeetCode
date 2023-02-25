#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
        int m = (l + r)/2;
        if (nums[m] < target)
            l = m + 1;
        else
            r = m;
    }

    return l;
}

int main(){
    vector<int> nums = {1,3,5,6};
    int target = 5;
    cout << searchInsert(nums, target) << endl;

    return 0;
}