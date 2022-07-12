#include<iostream>
#include<vector>
#include<iterator>
#include<map>
using namespace std;

vector<int> twosums(vector<int> nums, int target){
    vector<int> ans;
    map<int, int> hmap;

    for (int i = 0; i < nums.size(); i++){
        int inverse_num = target - nums[i];
        if (hmap.find(nums[i]) == hmap.end()){
            hmap.insert(pair<int, int>(inverse_num, i));

        } else {
            map<int, int>::iterator itr = hmap.find(nums[i]);
            ans.push_back(itr->second);
            ans.push_back(i);

            return ans;
        }
    }
    return ans;
}

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(6);

    int target = 9;

    vector<int> ans = twosums(nums, target);

    cout<<'['<<ans[0]<<','<<ans[1]<<']'<<endl;

    return 0;
}