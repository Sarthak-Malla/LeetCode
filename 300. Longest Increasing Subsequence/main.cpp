#include<iostream>
#include<vector>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> length(nums.size(), 1);
    int idx = 0;

    for (int i = 1; i < nums.size(); i++) {
        int prev = i - 1;
        while (prev >= 0) {
            if (nums[i] > nums[prev]) {
                length[i] = max(length[i], length[prev] + 1);
            }

            prev--;
        }
        if (length[idx] < length[i])
            idx = i;
    }

    return length[idx];
}

int main(){
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums) << endl;

    return 0;
}
