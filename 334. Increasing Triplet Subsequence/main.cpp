#include<iostream>
#include<vector>
using namespace std;

bool increasingTriplet(vector<int>& nums) {
    vector<int> m(nums.size(), nums[nums.size() - 1]), mi(nums.size(), nums[0]);

    for (int i = 1; i < nums.size(); i++) 
        mi[i] = min(mi[i-1], nums[i]);
    
    for (int i = nums.size() - 2; i >= 0; i--) 
        m[i] = max(m[i+1], nums[i]);

    for (int i = 1; i < nums.size() - 1; i++) {
        if (nums[i] > mi[i-1] && nums[i] < m[i+1]) {
            return true;
        }
    }

    return false;
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    cout << boolalpha << increasingTriplet(nums) << endl;

    return 0;
}