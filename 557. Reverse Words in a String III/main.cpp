#include<iostream>
#include<string>
using namespace std;

string reverse(string s) {
    string ans = "";
    for (int i = s.size()-1; i >= 0; i--) {
        ans += s[i];
    }
    return ans;
}

string reverseWords(string s) {
    int left = 0;
    s = s + ' ';
    string ans = "";

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            ans += reverse(s.substr(left, i - left)) + ' ';
            left = i + 1;
        }
    }

    return ans.substr(0, s.size() - 1);
}

int main(){
    string s = "Let's take LeetCode contest";

    cout<<reverseWords(s)<<endl;

    return 0;
}