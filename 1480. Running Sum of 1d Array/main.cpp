#include<iostream>
#include<vector>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    vector<int> sum(nums.size());
    int s = 0;
    for (int i = 0; i < nums.size(); i++) {
        s += nums[i];
        sum[i] = s;
    }

    return sum;
}

int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> sum = runningSum(nums);
    for (int i = 0; i < sum.size(); i++) {
        cout << sum[i] << " ";
    }
    cout << endl;

    return 0;
}