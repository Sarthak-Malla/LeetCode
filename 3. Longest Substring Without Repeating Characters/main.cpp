#include<iostream>
#include<string>
#include<map>
#include<iterator>
using namespace std;

int lengthOfLongestSubstring(string s){
    map<char, int> seen;

    int len = 0;
    int longest = 0;

    if (s.length() == 1)
        return 1;

    for (int i = 0; i < s.length(); i++){
        if (seen.find(s[i]) == seen.end())
            len++;
        else{
            if (i - seen[s[i]] == 1 && i != 1)
                len--;
            else 
                len -= seen[s[i]];
                if (len < 0)
                    len = 0;
        }

        if (len > longest)
            longest = len;
        
        seen[s[i]] = i;
    }

    return longest;
}

int main(){
    string s = "cxyzjmnopkilbkd";

    int length = lengthOfLongestSubstring(s);

    cout<<length<<endl;
    return 0;
}