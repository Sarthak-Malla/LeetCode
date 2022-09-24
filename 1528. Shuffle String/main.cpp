#include<iostream>
#include<vector>
using namespace std;

string restoreString(string s, vector<int>& indices) {
    vector<char> ans(s.size(), ' ');
    for (int i = 0; i < s.size(); i++) {
        ans[indices[i]] = s[i];
    }
    
    string a = "";
    for (int i = 0; i < ans.size(); i++) {
        a += ans[i];
    }
    
    return a;
}

int main(){
    

    return 0;
}