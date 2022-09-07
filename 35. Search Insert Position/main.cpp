#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int mid = (right)/2;
    bool found = false;

    if (right == left){
        if (nums[left] == target)
            return left;
        else if (target < nums[left])
            return 0;
        else if (target > nums[left])
            return 1;
    }
    // 1 3 5 7
    while (right - left > 1) {
        mid = (right-left)/2 + left; // 1 2
        if (target < nums[mid]) {
            right = mid;
        } else if (target > nums[mid]) {
            left = mid; // 1 2
        } else {
            found = true;
            break;
        }
    }

    if (target == nums[left])
        return left;
    
    if (target == nums[right])
        return right;

    if (!found) {
        if (target < nums[left]) {
            if (left == 0)
                return left;
        }

        if (target > nums[right]) {
            if (right == nums.size() - 1)
                return right + 1;
            return nums.size() - 1;
        }

        if (target < nums[mid]){
            return mid;
        } else if (target > nums[mid]) {
            if (mid == nums.size() - 1)
                return mid + 1;
            return nums.size() - 1;
        }
    }

    return mid;
}

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);

    int target = 3;

    cout<<searchInsert(nums, target)<<endl;

    return 0;
}