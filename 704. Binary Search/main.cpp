#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int mid;
    bool found = false;

    if (left == right && target == nums[left])
        return 0;

    while (right - left > 1) {
        mid = (right-left)/2 + left;
        if (target < nums[mid]) {
            right = mid;
        } else if (target > nums[mid]) {
            left = mid;
        } else {
            found = true;
            break;
        }
    }

    if (target == nums[left])
        return left;
    
    if (target == nums[right])
        return right;

    if (!found)
        return -1;

    return mid;
}

int main(){
    vector<int> nums;
    nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(3);
    // nums.push_back(4);
    // nums.push_back(5);

    cout<<search(nums, 2)<<endl;

    return 0;
}