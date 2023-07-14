#include <bits/stdc++.h>

using namespace std;

int popular(vector<int>& counts) {
	int ans = 0;
	for (int count : counts)
		ans = max(count, ans);
	return ans;
}
int characterReplacement(string s, int k) {
	int n = s.size();
	int l = 0;
	vector<int> counts(26, 0);
	int res = 0;

	for (int i = 0; i < n; i++) {
		counts[s[i] - 'A']++;
		int temp = (i - l + 1) - popular(counts);
		if (temp <= k) {
			res = max(i - l + 1, res);
		} else {
			counts[s[l] - 'A']--;
			l++;
		}
	}

	return res;
}

int main(){
	string s = "ABAB";
	int k = 2;
	cout << characterReplacement(s, k) << endl;

	return 0;
}