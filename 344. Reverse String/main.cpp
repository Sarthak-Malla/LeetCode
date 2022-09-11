#include<iostream>
#include<vector>
using namespace std;

void reverseString(vector<char>& s) {
    int left = 0, right = s.size() - 1;

    while (left < right) {
        swap(s[left++], s[right--]);
    }
}

int main(){
    vector<char> s;
    s.push_back('h');
    s.push_back('e');
    s.push_back('l');
    s.push_back('l');
    s.push_back('o');

    reverseString(s);

    for (int i = 0; i < s.size(); i++) {
        cout<<s[i]<<endl;
    }

    return 0;
}