#include<iostream>
#include<vector>
using namespace std;

int binarySearchMin(vector<int>& nums, int left, int right) {
    int mid = (left + right) / 2;
    if (nums[left] < nums[right])
        return left;

    if (abs(left - right) <= 1) {
        return nums[left] < nums[right] ? left : right;
    }

    if (nums[left] < nums[mid])
        return binarySearchMin(nums, mid, right);
    return binarySearchMin(nums, left, mid);
}
int binarySearch(vector<int>& nums, int left, int right, int target) {
    int mid = (right + left) / 2;
    if (nums[mid] == target)
        return mid;
    
    if (abs(left - right) <= 1) {
        if (nums[left] == target)
            return left;
        else if (nums[right] == target)
            return right;
        else
            return -1;
    }
    
    if (target < nums[mid])
        return binarySearch(nums, left, mid, target);
    return binarySearch(nums, mid, right, target);
}
int search(vector<int>& nums, int target) {
    int min = binarySearchMin(nums, 0, nums.size() - 1);

    if (target > nums[nums.size() - 1])
        return binarySearch(nums, 0, min, target);

    return binarySearch(nums, min, nums.size() - 1, target);
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << search(nums, target) << endl;


    return 0;
}
