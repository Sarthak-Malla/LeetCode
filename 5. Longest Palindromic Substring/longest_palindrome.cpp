#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isPalindrome(string s){
    string reversed = "";

    for (int i = 0; i < s.length(); i++){
        reversed = s[i] + reversed;
    }

    return (s == reversed);
}

string longestPalindrome(string s){
    int len = s.length();
    vector<vector<int> > mat;
    vector<int> inside;
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            inside.push_back(-1);
        }

        mat.push_back(inside);
        inside.clear();
    }

    if (len == 1)
        return s;

    for (int i = 0; i < len; i++){
        
    }
}

int main(){

    string s = "babad";

    cout<<longestPalindrome(s)<<endl;

    return 0;
}