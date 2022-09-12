#include<iostream>
using namespace std;

bool isIn(string s1, string s2) {
    for (int index = 0; index < s1.length(); index++) {
        bool found = false;

        for (int i = 0; i < s2.length(); i++) {
            if (s1[index] == s2[index])
                found = true;
                continue;
            
            if (!found)
                return false;
        }
    }

    return true;
}

bool checkInclusion(string s1, string s2) {
    int left = 0, len = s1.length() - 1;

    while (left < s2.length() - s1.length() + 1) {
        if (isIn(s1, s2.substr(left, len)))
            return true;
        left++;
    }

    return false;
}

int main(){
    string s1 = "aba";
    string s2 = "eidbaooo";

    cout<<boolalpha<<checkInclusion(s1, s2)<<endl;

    return 0;
}