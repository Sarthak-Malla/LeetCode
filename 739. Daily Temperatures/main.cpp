#include <bits/stdc++.h>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
	int n = temperatures.size();
	stack<pair<int, int>> s;
	vector<int> ans(n, 0);

	pair<int, int> p(temperatures[n-1], n-1);
	s.push(p);

	for (int i = n - 2; i >= 0; i--) {
		while (!s.empty() && s.top().first <= temperatures[i]) {
			s.pop();
		}
		if (!s.empty())
			ans[i] = s.top().second - i;
		p.first = temperatures[i]; p.second = i;
		s.push(p);
	}

	return ans;
}

int main(){
	vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
	vector<int> ans = dailyTemperatures(temperatures);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}