#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums, int left, int right) {
    // base case
    if (nums[left] < nums[right])
        return nums[left];
    
    // getting the middle
    int mid = (left + right)/2;

    // this only happens when we are down to 2 elements
    if (mid == left)
        return min(nums[left], nums[right]); // the smaller one is the answer
    
    // condition of the minimum to be on the left of mid
    if (nums[mid] < nums[right] || nums[mid] < nums[left]) 
        return binarySearch(nums, left, mid);

    return binarySearch(nums, mid, right);
}

int findMin(vector<int>& nums) {
    return binarySearch(nums, 0, nums.size() - 1);
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << findMin(nums) << endl;

    return 0;
}
