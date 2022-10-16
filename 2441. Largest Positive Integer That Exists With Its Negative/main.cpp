#include<iostream>
#include<vector>
using namespace std;

int findMaxK(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        if (nums[left] > 0)
            break;
        if (abs(nums[left]) == nums[right])
            return abs(nums[left]);
        else if (abs(nums[left]) < nums[right])
            right--;
        else
            left++;
    }
    
    return -1;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << findMaxK(nums) << endl;

    return 0;
}