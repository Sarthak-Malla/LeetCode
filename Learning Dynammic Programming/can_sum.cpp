#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool can_sum(int targetSum, vector<int> num, unordered_map<int, bool> memo){
    if (memo.find(targetSum) != memo.end()) return memo[targetSum];

    if (targetSum == 0) return true;
    if (targetSum < 0) return false;

    for (int i = 0; i < num.size(); i++){
        if (can_sum(targetSum - num[i], num, memo) == true){
            memo[targetSum] = true;
            return true;
        }
    }

    memo[targetSum] = false;
    return false;
}

int main(){
    int s = 300;
    vector<int> n;
    unordered_map<int, bool> memo;

    n.push_back(7);
    n.push_back(14);
    // n.push_back(4);
    // n.push_back(7);

    cout<<boolalpha<<can_sum(s,n,memo)<<endl;

    return 0;
}