#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1;
    int mid;

    while (left <= right) {
        mid = (left + right)/2;
        if (nums[mid] == target)    
            return mid;
        
        if (nums[left] <= nums[mid]) {
            if (target > nums[mid] || target < nums[left])
                left = mid + 1;
            else
                right = mid - 1;
        } else {
            if (target < nums[mid] || target >= nums[left])
                right = mid - 1;
            else
                left = mid + 1;
        }
    }

    return -1;
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << search(nums, target) << endl;

    return 0;
}