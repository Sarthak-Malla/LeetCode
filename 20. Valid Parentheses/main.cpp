#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
	stack<char> hash;
	int n = s.size();

	for (int i = 0; i < n; i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			hash.push(s[i]);
		else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
			if (hash.empty())
				return false;
			
			char o = hash.top();
			hash.pop();

			if (o == '(' && s[i] == ')' || o == '{' && s[i] == '}' || o == '[' && s[i] == ']')
				continue;
			else
				return false;
		}
	}

	if (!hash.empty())
		return false;

	return true;
}

int main(){
	string s;
	cin >> s;

	if (isValid(s))
		cout << "Valid" << endl;
	else
		cout << "Invalid" << endl;

	return 0;
}