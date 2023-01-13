#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int maximum = 1;

int dfs(string& s, int curr) {
	int m1 = 0, m2 = 0;
	for (auto& idx : adj[curr]) {
		int temp = dfs(s, idx);

		if (s[idx] == s[curr])
			continue;
		
		if (temp > m1){
			m2 = m1;
			m1 = temp;
		} else {
			m2 = max(m2, temp);
		}
	}

	maximum = max(maximum, m1 + m2 + 1);
	return m1 + 1;
}
int longestPath(vector<int>& parent, string s) {
	int n = s.size();
	adj.resize(n);

	for (int i = 1; i < n; i++)
		adj[parent[i]].push_back(i);

	dfs(s, 0);
	return maximum;
}

int main(){
	vector<int> parent = { -1, 0, 0, 1, 1, 2, 2 };
	string s = "abbaaa";
	cout << longestPath(parent, s) << endl;

	return 0;
}