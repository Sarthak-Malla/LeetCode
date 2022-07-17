#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isPalindrome(string s){
    string reversed = "";

    for (int i = 0; i < s.length(); i++){
        reversed += s[i];
    }

    return (s == reversed);
}

string longestPalindrome(string s){
    
}

int main(){

    string s = "babad";

    string ans = longestPalindrome(s);   

    cout<<ans<<endl; 

    return 0;
}