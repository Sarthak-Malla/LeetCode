#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int gridTraveller(int m, int n, unordered_map<string, int> memo){
    string key = to_string(m) + ',' + to_string(n);
    if (memo.find(key) != memo.end())
        return memo[key];

    if (m == 1 && n == 1) return 1;
    if (m == 0 || n == 0) return 0;

    memo[key] = gridTraveller(m - 1, n, memo) + gridTraveller(m, n - 1, memo);

    return memo[key];
}

int main(){
    unordered_map<string, int> memo;
    cout<<gridTraveller(18,10, memo)<<endl;

    return 0;
}