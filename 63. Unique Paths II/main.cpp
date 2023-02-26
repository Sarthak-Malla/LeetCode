#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();

	// no paths are possible if the destination is itself an obstacle
	if (obstacleGrid[m-1][n-1] == 1)
		return 0;

	// a 2d vector that stores all the intermediate values, such that we look at the number of ways to get to [i-1][j] and the number of ways to get to [i][j-1]
	vector<vector<int>> dp(m, vector<int>(n, 1));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			// starting point
			if (i == 0 && j == 0)
				continue;
			
			// for edges
			int up = 0, left = 0;
			if (i - 1 >= 0) {
				up = dp[i - 1][j];

				// if the cell is obstacle there is no path there
				if (obstacleGrid[i-1][j] == 1)
					up = 0;
			}
			if (j - 1 >= 0) {
				left = dp[i][j - 1];

				// if the cell is obstacle there is no path there
				if (obstacleGrid[i][j-1] == 1)
					left = 0;
			}
			
			// paths to this cell is the number of ways to get to the cell up, and cell to the left
			dp[i][j] = up + left;
		}
	}

	// total number of ways is computed in the destination cell.
	return dp[m-1][n-1];
}

int main(){
	vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
	cout << uniquePathsWithObstacles(obstacleGrid) << endl;

	return 0;
}