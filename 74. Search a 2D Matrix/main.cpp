#include <bits/stdc++.h>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int m = matrix.size();
	int n = matrix[0].size();
	if (m == 1 && n == 1) return (matrix[0][0] == target);
	int row = 0;

	int l = 0, r = m-1;
	while (l <= r) {
		int mid = (l+r)/2;
		if (matrix[mid][0] == target)
			return true;
		else if (matrix[mid][0] < target) {
			if (matrix[mid][n-1] >= target) {
				row = mid;
				break;
			}
			l = mid+1;
		} else {
			r = mid-1;
		}
	}

	l = 0, r = n-1;
	while (l <= r) {
		int mid = (l+r)/2;
		if (matrix[row][mid] == target)
			return true;
		else if (matrix[row][mid] < target)
			l = mid+1;
		else
			r = mid-1;
	}

	return false;
}

int main(){
	int m, n;
	cin >> m >> n;
	vector<vector<int>> matrix(m, vector<int>(n));
	for (int i = 0; i < m; ++i) 
		for (int j = 0; j < n; ++j)
			cin >> matrix[i][j];
	int target;
	cin >> target;
	cout << searchMatrix(matrix, target) << endl;

	return 0;
}