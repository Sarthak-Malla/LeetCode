#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums, int left, int right) {
    int mid = (right - left)/2 + left;
    int curr_min = min(nums[left], nums[right]);
    if (left == right || abs(left - right) == 1)
        return curr_min;

    if (nums[left] < nums[mid])
        return min(nums[left], binarySearch(nums, mid, right));
    else if (nums[mid] < nums[left])
        return min(nums[mid], binarySearch(nums, left, mid));
    
    return nums[mid];
}

int findMin(vector<int>& nums) {
    return binarySearch(nums, 0, nums.size() - 1);
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << findMin(nums) << endl;

    return 0;
}
