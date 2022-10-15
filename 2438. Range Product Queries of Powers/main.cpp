#include<iostream>
#include<vector>
using namespace std;

vector<int> productQueries(int n, vector<vector<int>>& queries) {
    vector<int> powers;
    vector<int> ans;
    int bit = 0;
    for (int i = 0; i < 32; i++) {
        bit = n & 1;
        if (bit == 1) {
            powers.push_back(pow(2, i));
        }
        n >>= 1;
    }
    
    for (int i = 0; i < queries.size(); i++) {
        long prod = 1;
        for (int j = queries[i][0]; j <= queries[i][1]; j++) {
            prod = ((powers[j] % 1000000007) * prod) % 1000000007;
        }
        ans.push_back(prod);
    }
    
    return ans;
}

int main(){
    int n = 5;
    vector<vector<int>> queries = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    vector<int> ans = productQueries(n, queries);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout<<endl;

    return 0;
}