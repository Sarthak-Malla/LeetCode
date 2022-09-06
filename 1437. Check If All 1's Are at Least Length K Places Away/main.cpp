#include<iostream>
#include<vector>
using namespace std;

bool kLengthApart(vector<int>& nums, int k) {
    int counter = k;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            if (counter < k) {
                return false;
            }
            counter = 0;
        } else {
            counter++;
        }
    }

    return true;
}

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    // nums.push_back(1);
    // nums.push_back(0);
    // nums.push_back(0);
    // nums.push_back(1);
    // nums.push_back(0);
    int k = 2;

    cout<<boolalpha<<kLengthApart(nums, k)<<endl;

    return 0;
}