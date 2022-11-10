#include<iostream>
#include<stack>
using namespace std;

string removeDuplicates(string s) {
    stack<char> h;
    h.push(s[0]);
    
    for (int i = 1; i < s.size(); i++) {
        if (!h.empty() && s[i] == h.top()) {
            h.pop();
            continue;
        }

        h.push(s[i]);
    }

    string ans = "";
    while (!h.empty()) {
        ans = h.top() + ans;
        h.pop();
    }

    return ans;
}

int main(){
    cout<<removeDuplicates("abbaca")<<endl;

    return 0;
}