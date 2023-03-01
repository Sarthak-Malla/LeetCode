#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
	// map stores with insertion sort
	map<float, vector<vector<int>>> hash;

	for (auto point : points) {
		float d = sqrt(point[0]*point[0] + point[1]*point[1]);
		hash[d].push_back(point);
	}

	vector<vector<int>> res;
	for (auto i = hash.begin(); i != hash.end(); i++) {
		for (auto point : i->second) {
			if (k > 0)
				res.push_back(point);
			else
				break;

			k--;
		}

		if (k <= 0)
			break;
	}

	return res;
}

int main(){
	vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
	int k = 2;

	vector<vector<int>> res = kClosest(points, k);

	for (auto point : res) {
		cout << point[0] << " " << point[1] << endl;
	}

	return 0;
}