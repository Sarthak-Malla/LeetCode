#include <bits/stdc++.h>
using namespace std;

vector<int> hash;
vector<int> child;
int ans;

// union find implementation
int find(int curr) {
	if (hash[curr] == -1)
		return curr;
	return hash[curr] = find(hash[curr]);
}
void union_(int x, int y) {
	hash[x] = y;
}

int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
	int n = vals.size();
	hash.resize(n, -1);
	child.resize(n, 1);

	// sort edges by max value of the two nodes
	sort(edges.begin(), edges.end(), [&](vector<int>& a, vector<int>& b){
		return max(vals[a[0]], vals[a[1]]) < max(vals[b[0]], vals[b[1]]);
	});

	ans = 0;
	for (auto edge : edges) {
		int p1 = find(edge[0]);
		int p2 = find(edge[1]);


		if (vals[p1] < vals[p2])
			union_(p1, p2);
		else if (vals[p1] > vals[p2])
			union_(p2, p1);
		else {
			// if the values are the same, we can connect them
			union_(p1, p2);

			// add the number of paths that can be made from the two nodes
			ans += child[p1] * child[p2];

			// update the number of children of the parent
			child[p2] += child[p1];
		}
	}


	return ans + n;
}

int main(){
	vector<int> vals = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}};
	cout << numberOfGoodPaths(vals, edges) << endl;

	return 0;
}