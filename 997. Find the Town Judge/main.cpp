#include <bits/stdc++.h>
using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {
	// we know that the judge is trusted by everyone and trusts no one
	// this means that the judge will have n-1 incoming edges and 0 outgoing edges
	vector<int> incoming(n+1, 0);
	vector<int> outgoing(n+1, 0);

	for (auto x : trust) {
		incoming[x[1]]++;
		outgoing[x[0]]++;
	}

	// searching for the judge such that it has n-1 incoming edges and 0 outgoing edges
	for (int i = 1; i < n+1; i++) 
		if (incoming[i] == n-1 && outgoing[i] == 0)
			return i;

	// if no such judge exists
	return -1;
}

int main(){
	int n = 3;
	vector<vector<int>> trust = {{1,3},{2,3},{3,1}};
	cout << findJudge(n, trust) << endl;

	return 0;
}