#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
    k = k % nums.size();

    vector<int> right;

    for (int i = nums.size() - k; i < nums.size(); i++) {
        right.push_back(nums[i]);
    }

    int j = nums.size() - k - 1;
    while (j >= 0) {
        nums[j + k] = nums[j];
        j--;
    }
    
    for (int i = 0; i < right.size(); i++) {
        nums[i] = right[i];
    }
}

int main(){
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(-100);
    nums.push_back(3);
    nums.push_back(99);
    // nums.push_back(5);
    // nums.push_back(6);
    // nums.push_back(7);

    int k = 2;

    rotate(nums, k);

    for (int i = 0; i < nums.size(); i++) {
        cout<<nums[i]<<endl;
    }

    return 0;
}