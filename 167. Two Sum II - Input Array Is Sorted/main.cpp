#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = 1;
    vector<int> ans(2);

    while (left < right) {
        if (numbers[left] + numbers[right] == target) {
            ans[0] = left+1;
            ans[1] = right+1;

            return ans;
        } else if (numbers[left] + numbers[right] > target) {
            left++;
            right--;
        } else if (right == numbers.size() - 1) {
            left++;
        } else {
            right++;
        }
    }

    return ans;
}

int main(){
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(25);
    nums.push_back(75);
    nums.push_back(79);
    nums.push_back(88);
    nums.push_back(150);
    nums.push_back(345);

    int target = 200;

    vector<int> ans = twoSum(nums, target);

    cout<<'['<<ans[0]<<", "<<ans[1]<<']'<<endl;

    return 0;
}