#include<iostream>
#include<stack>
#include<string>
using namespace std;

int minInsertions(string s){
    stack<char> openingBraces;
    
    int count = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '('){
            openingBraces.push('(');
        }

        if (openingBraces.empty() && s[i] == ')' && i+1 < s.length() && s[i+1] == ')'){
            count++;
            i = i+1;
        } else if (openingBraces.empty() && s[i] == ')'){
            count += 2;
        }

        if (!openingBraces.empty() && s[i] == ')' && i+1 < s.length() && s[i+1] == ')'){
            openingBraces.pop();
            i = i+1;
        } else if (!openingBraces.empty() && s[i] == ')'){
            count++;
            openingBraces.pop();
        }
    }
    
    count += openingBraces.size() * 2;

    return count;
}

int main(){
    string s = "()()()()()(";

    int ans = minInsertions(s);

    cout<<ans<<endl;

    return 0;
}