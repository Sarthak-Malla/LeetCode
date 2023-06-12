#include <bits/stdc++.h>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    int n = nums.size();
    vector<string> ans;
    if (n < 1) return ans;

    int prev = nums[0];
    int first = prev;
    int last = prev;

    for (int i = 1; i < n; i++) {
        if (nums[i] - 1 != prev) {
            if (last == first) {
                ans.push_back(to_string(first));
            } else {
                ans.push_back(to_string(first) + "->" + to_string(last));
            }

            first = nums[i];
        }
        last = nums[i];
        prev = last;
    }

    if (last == first) {
        ans.push_back(to_string(first));
    } else {
        ans.push_back(to_string(first) + "->" + to_string(last));
    }

    return ans;
}

int main() {
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    vector<string> ans = summaryRanges(nums);

    for (string s : ans) {
        cout << s << endl;
    }

	return 0;
}