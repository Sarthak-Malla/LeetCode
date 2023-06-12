#include <bits/stdc++.h>

using namespace std;

int countNegatives(vector<vector<int>>& grid) {
	int count = 0;
	int m = grid.size();
	int n = grid[0].size();

	for (int i = 0; i < m; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (grid[i][j] < 0)
				count++;
			else
				continue;
		}
	}

	return count;
}

int main(){
	vector<vector<int>> grid = {{4,3,2,-1},
								{3,2,1,-1},
								{1,1,-1,-2},
								{-1,-1,-2,-3}};
	cout << countNegatives(grid) << endl;
	
	return 0;
}