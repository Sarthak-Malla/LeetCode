#include<iostream>
#include<map>
#include<iterator>
#include<vector>
using namespace std;
typedef map<char,int>::iterator iterate;

bool isIn(string s1, string s2, vector<int> &hash) {
    vector<int> hash2(26, 0);
    for (int i = 0; i < s2.size(); i++) {
        hash2[s2[i] - 'a']++;
    }
    
    for (int i = 0; i < 26; i++) {
        if (hash[i] != hash2[i])
            return false;
    }
    
    return true;
}

bool checkInclusion(string s1, string s2) {
    int left = 0, n = s1.length();
    if (n > s2.length())
        return false;
    
    vector<int> hash(26, 0);
    for (int i = 0; i < s1.size(); i++) {
        hash[s1[i] - 'a']++;
    }

    while (left < s2.length() - n + 1) {
        if (isIn(s1, s2.substr(left, n), hash))
            return true;

        left++;
    }

    return false;
}

int main(){
    string s1 = "ab";
    string s2 = "abcde";

    cout<<boolalpha<<checkInclusion(s1, s2)<<endl;

    return 0;
}