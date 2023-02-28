#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int n;
void helper(int l, int r, string& s) {
	while (l >= 0 && r < n && s[l] == s[r]) {
		ans++;
		l--;
		r++;
	}
}
int countSubstrings(string s) {
	n = s.size();

	for (int i = 0; i < n; i++) {
		// odd length palindromes
		helper(i, i, s);

		// even length palindromes
		helper(i, i+1, s);
	}

	return ans;
}

int main(){

	return 0;
}