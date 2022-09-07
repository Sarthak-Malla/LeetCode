#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> s;
    int sq;
    for (int i = 0; i < nums.size(); i++) {
        sq = pow(nums[i], 2);
        if (i == 0) {
            s.push_back(sq);
        }
        for (int j = 0; j < s.size(); j++) {
            if (s[j] > sq || s[j] == sq) {
                s.insert(s.begin() + j, sq);
                break;
            } else if (sq > s[s.size() - 1]) {
                s.push_back(sq);
            }
        }
    }

    return s;
}

int main(){
    vector<int> nums;
    nums.push_back(-10);
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(10);

    vector<int> ans = sortedSquares(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<endl;
    }

    return 0;
}