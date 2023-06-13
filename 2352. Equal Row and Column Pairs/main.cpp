#include <bits/stdc++.h>

using namespace std;

string get_string(vector<int>& vec) {
	string res = "";

	for (int num : vec) {
		res += to_string(num) + ",";
	}

	return res;
}
int equalPairs(vector<vector<int>>& grid) {
	map<string, int> hash;
	int count = 0;
	int n = grid.size();

	for (int i = 0; i < n; i++) {
		string s = get_string(grid[i]);

		hash[s]++;
	}

	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < n; j++) {
			temp.push_back(grid[j][i]);
		}
		
		count += hash[get_string(temp)];
	}

	return count;
}

int main(){
	vector<vector<int>> grid = {{1, 2, 3}, {3, 2, 1}, {1, 2, 3}};
	cout << equalPairs(grid) << endl;

	return 0;
}