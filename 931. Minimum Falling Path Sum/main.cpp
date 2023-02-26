#include <bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
	int n = matrix.size();

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int left = INT_MAX, right = INT_MAX;
			if (j - 1 >= 0)
				left = matrix[i - 1][j - 1];
			if (j + 1 < n)
				right = matrix[i - 1][j + 1];
			
			int two = min(left, matrix[i-1][j]);
			matrix[i][j] = min(two, right) + matrix[i][j];
		}
	}

	vector<int> last = matrix[n - 1];
	sort(last.begin(), last.end());

	return last[0];
}

int main(){
	vector<vector<int>> matrix = {
		{2,1,3},
		{6,5,4},
		{7,8,9}
	};

	cout << minFallingPathSum(matrix) << endl;

	return 0;
}