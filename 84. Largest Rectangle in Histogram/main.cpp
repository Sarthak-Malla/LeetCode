#include <bits/stdc++.h>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
	int n = heights.size();
	int max_ = 0;
	stack<pair<int, int>> s;

	for (int i = 0; i < n; i++) {
		int start = i;
		while (!s.empty() && s.top().second > heights[i]) {
			max_ = max(max_, s.top().second * (i - s.top().first));
			start = s.top().first;
			s.pop();
		}

		s.push(pair<int, int>(start, heights[i]));
	}

	while (!s.empty()) {
		max_ = max(max_, s.top().second * (n - s.top().first));
		s.pop();
	}

	return max_;
}

int main(){
	vector<int> heights = {2, 1, 5, 6, 2, 3};
	cout << largestRectangleArea(heights) << endl;

	return 0;
}