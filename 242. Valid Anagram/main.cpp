#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
	vector<int> hash(26, 0);
	vector<int> hash2(26, 0);
	int sn = s.size(), tn = t.size();
	if (sn != tn)
		return false;

	for (int i = 0; i < sn; i++) {
		hash[s[i] - 'a']++;
		hash2[t[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (hash[i] != hash2[i])
			return false;
	}

	return true;
}

int main(){
	string s, t;
	cin >> s >> t;
	cout << isAnagram(s, t) << endl;

	return 0;
}