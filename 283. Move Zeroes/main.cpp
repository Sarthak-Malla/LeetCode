#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int zero_pointer = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            int temp = nums[i];
            nums[i] = nums[zero_pointer];
            nums[zero_pointer] = temp;
            zero_pointer++;
        }
    }
}

int main(){
    vector<int> nums;
    nums.push_back(1); // 1
    nums.push_back(1); // 0
    nums.push_back(0); // 0
    nums.push_back(3); // 
    nums.push_back(0); // 0
    nums.push_back(0); // 0
    nums.push_back(0); // 0
    nums.push_back(0); // 0
    nums.push_back(12);

    moveZeroes(nums);

    for (int i = 0; i < nums.size(); i++) {
        cout<<nums[i]<<endl;
    }

    return 0;
}