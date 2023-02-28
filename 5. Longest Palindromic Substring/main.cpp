#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
	int n = s.size();
	int len = 0;
	string res = "";

	for (int i = 0; i < n; i++) {
		// odd
		int l = i, r = i;
		while (l >= 0 && r < n && s[l] == s[r]) {
			if ((r - l + 1) > len) {
				len = r-l+1;
				res = s.substr(l, len);
			}
			l--;
			r++;
		}

		// even
		l = i, r = i + 1;
		while (l >= 0 && r < n && s[l] == s[r]) {
			if ((r - l + 1) > len) {
				len = r-l+1;
				res = s.substr(l, len);
			}
			l--;
			r++;
		}
	}

	return res;
}

int main(){
	string s = "babad";
	cout << longestPalindrome(s) << endl;

	return 0;
}