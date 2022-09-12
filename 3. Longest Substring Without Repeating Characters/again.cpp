#include<iostream>
#include<string>
#include<vector>
#include<iterator>
using namespace std;

int lengthOfLongestSubstring(string s) {
    if (s.length() == 0)
        return 0;
    else if (s.length() == 1)
        return 1;
    
    int left = 0, right = 1;
    int len = 0;

    while (left <= right && right < s.length()) {
        if (s[left] == s[right] && left != right){
            left++; // 1 
        } else {
            if (right - left + 1 > len)
                len = right - left + 1; // 2 3 
            right++; // 2 3 
        }
    }

    return len;
}

int main(){

    string s = "abacadab";

    cout<<lengthOfLongestSubstring(s)<<endl;

    return 0;
}