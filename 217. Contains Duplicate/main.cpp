#include<iostream>
#include<vector>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    if (nums.size() == 1)
        return false;
    
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size(); i++) {
        if (i + 1 < nums.size()) {
            if (nums[i] == nums[i+1])
                return true;
        }
    }
    
    return false;
}

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);

    cout<<boolalpha<<containsDuplicate(nums)<<endl;

    return 0;
}
