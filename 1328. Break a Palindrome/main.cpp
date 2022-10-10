#include<iostream>
using namespace std;

string breakPalindrome(string palindrome) {
    int flag = false;
    int left = 0, right = palindrome.size() - 1;
    while (left <= right) {
        if (left == right) {
            left++;
            right--;
            continue;
        }

        if (palindrome[left] != 'a') {
            palindrome[left] = 'a';
            flag = true;
            break;
        }

        left++;
        right--;
    }

    if (!flag) {
        if (palindrome.size() == 1)
            return "";
        
        palindrome[palindrome.size() - 1] = palindrome[palindrome.size() - 1] + 1;
    }

    return palindrome;
}

int main(){
    string palindrome = "abccba";
    cout << breakPalindrome(palindrome) << endl;

    return 0;
}