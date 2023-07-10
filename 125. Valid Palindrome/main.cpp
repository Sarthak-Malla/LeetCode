#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
	int n = s.size();
	string t = "";
	for (char a : s)
		t += tolower(a);
	
	int l = 0, r = n - 1;
	while (l < r) {
		if (!iswalnum(t[l]))
			l++;
		else if (!iswalnum(t[r]))
			r--;
		else {
			if (t[l] != t[r])
				return false;
			l++; r--;
		}
	}

	return true;
}

int main(){
	string s = "hydrogen";
	cout << isPalindrome(s) << endl;

	return 0;
}