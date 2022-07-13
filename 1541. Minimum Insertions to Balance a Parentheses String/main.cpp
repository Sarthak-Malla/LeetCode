#include<iostream>
#include<stack>
#include<string>
using namespace std;

int minInsertions(string s){
    stack<char> openingBraces;

    for (int i = 0; i < s.length(); i++){
        if (openingBraces.empty() && s[i] == ')')
            return 0;
        
        if (s[i] == '(')
            openingBraces.push('(');
        else if (i+1 < s.length() && s[++i] == ')')
            openingBraces.pop();
    }

    if (openingBraces.empty())
        return 1;

    return -1;
}

int main(){
    string s = "())(())))";

    int ans = minInsertions(s);

    cout<<ans<<endl;

    return 0;
}