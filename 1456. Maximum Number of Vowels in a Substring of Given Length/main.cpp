#include <bits/stdc++.h>

using namespace std;

int maxVowels(string s, int k) {
	int n = s.size();
	if (n < k)
		return 0;

	int l = 0, r = 0;
	vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

	int curr = 0;
	int max_ = 0;
	vector<int> hash(n, 0);
	while (r < n) {
		if (find(vowels.begin(), vowels.end(), s[r]) != vowels.end()) {
			curr++;
			hash[r]++;
		}
		
		if (r > l + k - 1) {
			if (hash[l])
				curr--;
			l++;
		}

		max_ = max(max_, curr);

		r++;
	}

	return max_;
}

int main(){
	string s = "abciiidef";
	int k = 3;

	cout << maxVowels(s, k) << endl;

	return 0;
}