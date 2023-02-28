#include <bits/stdc++.h>
using namespace std;

vector<string> bracks = {"(", ")"};
set<string> ans;
bool check(string& s) {
	int open = 0;
	int n = s.size();
	if (n < 1)
		return false;
	for (int i = 0; i < n; i++) {
		if (open == 0 && s[i] == ')')
			return false;
		if (s[i] == '(')
			open++;
		else if (s[i] == ')')
			open--;
	}

	if (open != 0)
		return false;
	return true;
}
void backtrack(string& s, int start, int n) {
	if (check(s) && s.size() == 2 * n)
		ans.insert(s);

	for (int i = start; i < 2*n; i++) {
		for (int j = 0; j < 2; j++) {
			s += bracks[j];
			backtrack(s, i+1, n);
			s.pop_back();
		}
	}
}
vector<string> generateParenthesis(int n) {
	string s = "";
	backtrack(s, 0, n);
	vector<string> res;
	for (auto x : ans)
		res.push_back(x);

	return res;
}

int main(){
	int n;
	cin >> n;
	vector<string> res = generateParenthesis(n);
	for (auto x : res)
		cout << x << endl;

	return 0;
}