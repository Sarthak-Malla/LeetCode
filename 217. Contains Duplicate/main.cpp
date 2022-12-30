#include <iostream>
#include <vector>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++) {
        if (hash.find(nums[i]) != hash.end())
            return true;

        hash[nums[i]] = 1;
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
