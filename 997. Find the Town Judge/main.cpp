#include <bits/stdc++.h>
using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {
	if (n < 2)
		return n;
	
	vector<vector<int>> adj(n+1);
	int len = trust.size();
	// making an adj list
	for (auto elem : trust)
		adj[elem[0]].push_back(elem[1]);

	vector<int> vec;
	int empty_count = 0;

	// finding the first non-empty vector
	for (int i = 1; i < n+1; i++) {
		if (!adj[i].empty()) {
			vec = adj[i];
			break;
		}
	}
	
	// checking if there is more than one empty vector
	for (int i = 1; i < n+1; i++)
		if (adj[i].empty())
			empty_count++;

	// if there is more than one empty vector, return -1
	if (empty_count > 1)
		return -1;

	// checking if the first non-empty vector has the judge
	for (int i = 0; i < vec.size(); i++)
		if (adj[vec[i]].empty())
			return vec[i];

	return -1;
}

int main(){
	int n = 3;
	vector<vector<int>> trust = {{1,3},{2,3},{3,1}};
	cout << findJudge(n, trust) << endl;

	return 0;
}