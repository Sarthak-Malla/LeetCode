#include<iostream>
#include<vector>
using namespace std;

int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n) {
        ans += n & 1;
        n = n >> 1;
    }

    return ans;
}
vector<int> countBits(int n) {
    vector<int> ans(n+1, 0);

    for (int i = 0; i < ans.size(); i++) {
        ans[i] = hammingWeight(i);
    }

    return ans;
}

int main(){
    int n = 5;
    vector<int> ans = countBits(n);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}