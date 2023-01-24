#include <bits/stdc++.h>
using namespace std;

int snakesAndLadders(vector<vector<int>>& board) {
	int n = board.size();
	queue<int> hash;

	// stores minimum distance to reach the node
	vector<int> distance(n*n + 1, -1);

	// to make the 2d into a 1d vector
	vector<int> linear;
	bool alter = false;
	linear.push_back(-1);

	// making 1d vector
	for (int i = n - 1; i >= 0; i--) {
		if (!alter) {
			for (int j = 0; j < n; j++) {
				linear.push_back(board[i][j]);
			}
			alter = true;
		} else {
			for (int j = n - 1; j >= 0; j--) {
				linear.push_back(board[i][j]);
			}
			alter = false;
		}
	}

	// BFS
	// initial position
	hash.push(1);
	distance[1] = 0;

	while (!hash.empty()) {
		// getting the top element
		int curr = hash.front();
		hash.pop();

		// looking at the next 6 elements or the end
		for (int i = curr + 1; i <= min(curr + 6, n*n); i++) {
			// if the element is a snake or ladder
			int temp = (linear[i] != -1) ? linear[i] : i;

			// if the element is not visitedf
			if (distance[temp] == -1) {
				distance[temp] = distance[curr] + 1;
				hash.push(temp);
			}
		}
	}

	return distance[n*n];
}

int main(){
	int n;
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> board[i][j];
		}
	}
	cout << snakesAndLadders(board) << endl;

	return 0;
}