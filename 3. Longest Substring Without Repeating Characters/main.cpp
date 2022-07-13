#include<iostream>
#include<string>
#include<map>
#include<iterator>
using namespace std;

int lengthOfLongestSubstring(string s){
    map<char, int> seen;

    int len = 0;

    if (s.length() == 1)
        return 1;

    for (int i = 0; i < s.length(); i++){
        if (seen.find(s[i]) != seen.end() && i - seen[s[i]] > len)
            len = i - seen[s[i]];
        seen[s[i]] = i;
    }

    return len;
}

int main(){
    string s = "abacdef";

    int length = lengthOfLongestSubstring(s);

    cout<<length<<endl;
    return 0;
}