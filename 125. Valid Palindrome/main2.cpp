#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
    int n = s.size();
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        while (i < j && !iswalnum(s[i]))
            i++;
        while (i < j && !iswalnum(s[j]))
            j--;
        if (tolower(s[i]) != tolower(s[j]))
            return false;
    }

    return true;
}

int main(){
	string s = "hydrogen";
	cout << isPalindrome(s) << endl;

	return 0;
}