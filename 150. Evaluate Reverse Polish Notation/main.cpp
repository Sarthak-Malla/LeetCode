#include <bits/stdc++.h>

using namespace std;

int evaluate(int a, int b, string token) {
	if (token == "+")
		return a+b;
	else if (token == "-")
		return b-a;
	else if (token == "*")
		return a*b;
	return floor(b/a);
}
int evalRPN(vector<string>& tokens) {
	int n = tokens.size();
	if (n == 1)
		return stoi(tokens[0]);
	stack<int> s;
	for (string token : tokens) {
		if (token == "+" || token == "-" || token == "*" || token == "/") {
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();

			int res = evaluate(a, b, token);
			s.push(res);

			continue;
		}

		s.push(stoi(token));
	}

	return s.top();
}

int main(){
	vector<string> tokens = {"2", "1", "+", "3", "*"};
	cout << evalRPN(tokens) << endl;

	return 0;
}