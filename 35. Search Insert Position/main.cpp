#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int mid;
    bool found = false;

    if (left == right) {
        if (target == nums[left]) 
            return left;
        else if (target < nums[left])
            return 0;
        else
            return 1;
    }
    // 1 2 5 6 8
    while (right - left > 1) {
        mid = (right - left) / 2 + left; // 2
        if (target < nums[mid])
            right = mid;
        else if (target > nums[mid])
            left = mid; // 2
        else {
            found = true;
            return mid;
        }
    }

    if (target == nums[left])
        return left;
    if (target == nums[right])
        return right;
    
    if (target < nums[left])
        return left;
    else if (target > nums[left] && target < nums[right])
        return right;
    else if (target > nums[right])
        return right+1;

    return mid;
}

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(8);

    int target = 0;

    cout<<searchInsert(nums, target)<<endl;

    return 0;
}