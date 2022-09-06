#include<iostream>
#include<vector>
using namespace std;

bool kLengthApart(vector<int>& nums, int k) {
    vector<int> index;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            index.push_back(i);
        }

        if (index.size() >= 2) {
            if (index[index.size() - 1] - index[index.size() - 2] <= k) {
                return false;
            }
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