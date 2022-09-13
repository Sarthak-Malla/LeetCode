#include<iostream>
#include<map>
#include<iterator>
using namespace std;
typedef map<char,int>::iterator iterate;

bool isIn(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1 == s2;
}

bool checkInclusion(string s1, string s2) {
    int left = 0, n = s1.length();
    if (n > s2.length())
        return false;

    while (left < s2.length() - n + 1) {
        if (isIn(s1, s2.substr(left, n)))
            return true;

        left++;
    }

    return false;
}

int main(){
    string s1 = "ab";
    string s2 = "ab";

    cout<<boolalpha<<checkInclusion(s1, s2)<<endl;

    return 0;
}