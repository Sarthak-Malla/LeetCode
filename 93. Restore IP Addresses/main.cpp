#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> ans;

// checking for the validity of the substring
bool check(string substring) {
	if (substring.size() > 3 || (substring.size() > 1 && substring[0] == '0')) return false;
	if (stoi(substring) > 255) return false;
	return true;
}

vector<string> restoreIpAddresses(string s) {
	n = s.size();
	if (n < 4)
		return {};
	
	// generating all possible combinations of the string
	// we need three for loops to add three dots
	for (int i = 1; i < 4 && i < n; i++) { // every substring should be of max length 3 and limited by the total length of the string
		for (int j = i + 1; j < i + 4 && j < n; j++) {
			for (int k = j + 1; k < j + 4 && k < n; k++) {
				string first = s.substr(0, i);
				string second = s.substr(i, j-i);
				string third = s.substr(j, k-j);
				string fourth = s.substr(k);

				// addidng the valid combinations to the answer vector
				if (check(first) && check(second) && check(third) && check(fourth)) {
					ans.push_back(first + "." + second + "." + third + "." + fourth);
				}
			}
		}
	}

	return ans;
}

int main(){
	string s;
	cin >> s;
	vector<string> ans = restoreIpAddresses(s);
	for (auto x : ans) {
		cout << x << endl;
	}

	return 0;
}