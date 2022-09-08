#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> s;
    int sq;
    for (int i = 0; i < nums.size(); i++) { // 0
        sq = pow(nums[i], 2); // 100
        if (i == 0) {
            s.push_back(sq); // 100
        }
        int s_size = s.size(); // 1
        for (int j = 0; j < s_size; j++) { // 0
            if (i != 0 && (s[j] > sq || sq == s[j])) {
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
    // nums.push_back(-10);
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