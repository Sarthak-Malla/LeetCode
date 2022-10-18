#include<iostream>
using namespace std;

string countAndSay(int n) {
    if (n == 1)
        return "1";
    
    string str = countAndSay(n - 1) + "a";
    string ans = "";

    int count = 1;
    for (int i = 1; i < str.size(); i++) {
        if (str[i] == str[i-1])
            count++;
        else {
            ans += to_string(count) + str[i - 1];
            count = 1;
        }
    }

    return ans;
}

int main(){
    cout<<countAndSay(4)<<endl;

    return 0;
}