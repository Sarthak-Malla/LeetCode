#include<iostream>
#include<vector>
using namespace std;

vector<int> countBits(int n) {
    vector<int> ans(n + 1);
    ans[0] = 0;

    for (int i = 1; i < n + 1; i++) {
        ans[i] = ans[i/2] + (i%2);
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