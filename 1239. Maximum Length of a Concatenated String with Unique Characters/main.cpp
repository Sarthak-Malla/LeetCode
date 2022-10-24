#include<iostream>
#include<vector>
using namespace std;

int helper(vector<string>& arr, vector<bitset<26>>& bitarr, vector<bool>& exclude, bitset<26> current, int i) {
    if (i >= bitarr.size())
        return 0;
    
    int ans = helper(arr, bitarr, exclude, current, i + 1);

    if (!exclude[i] && (current & bitarr[i]).none()) 
        ans = max(ans, (int) arr[i].size() + helper(arr, bitarr, exclude, current | bitarr[i], i+1));
    
    return ans;
}
int maxLength(vector<string>& arr) {
    vector<bitset<26>> bitarr(arr.size(), bitset<26>());
    vector<bool> exclude(arr.size(), false);

    for (int i = 0; i < arr.size(); i++) {
        for (char c: arr[i]) {
            if (bitarr[i][c - 'a'])
                exclude[i] = true;

            bitarr[i][c - 'a'] = 1;
        }
    }

    return helper(arr, bitarr, exclude, bitset<26>(), 0);
}

int main(){
    // Not my solution: Soyuj's Solution

    return 0;
}