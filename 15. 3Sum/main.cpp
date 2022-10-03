#include<iostream>
#include<vector>
using namespace std;

void increment(vector<int>& nums, int& index) {
    do {
        index++;
    } while (index < nums.size() - 1 && nums[index - 1] == nums[index]);
}
void decrement(vector<int>& nums, int& index) {
    do {
        index--;
    } while (index > 0 && nums[index + 1] == nums[index]);
}
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> sums;
    vector<int> curr;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); increment(nums, i)) {
        int left = i+1, right = nums.size() - 1;

        while (left < right) {

            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                curr = {nums[i], nums[left], nums[right]};
                sums.push_back(curr);
                increment(nums, left);
                decrement(nums, right);

            } else if (sum > 0) {
                decrement(nums, right);
            } else if (sum < 0){
                increment(nums, left);
            }
        }
    }

    return sums;
}

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> sums = threeSum(nums);

    for (int i = 0; i < sums.size(); i++) {
        for (int j = 0; j < sums[i].size(); j++) {
            cout << sums[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}