#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>>& intervals, vector<int>& newInterval, int i, int j) {
	// if the starting and ending index are the same, we know that the new interval must be inserted at this index
	// there is no need to delete any intervals
	if (i == j) {
		intervals.insert(intervals.begin() + i, newInterval);
		return;
	}
	// getting the starting and ending index of the new interval
	int s = min(newInterval[0], intervals[i][0]);
	int e = max(newInterval[1], intervals[j-1][1]);

	// inserting the new interval and deleting the unwanted intervals
	intervals.insert(intervals.begin() + i, {s,e});
	i++;
	intervals.erase(intervals.begin() + i, intervals.begin() + j + 1);
}

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	int n = intervals.size();

	// case if the intervals is empty
	if (n == 0) {
		intervals.push_back(newInterval);
		return intervals;
	}

	int s = newInterval[0];
	int e = newInterval[1];

	// storing starting and ending index from which to delete and insert the intervals
	int st_index = -1;
	int en_index = -1;

	for (int i = 0; i < n; i++) {
		int curr_start = intervals[i][0];
		int curr_end = intervals[i][1];

		// if the start of the newInterval is less than or equal to the current end, 
		// we know that the new interval must be inserted before this interval, regardless of the current start
		if (st_index < 0 && s <= curr_end)
			st_index = i;
		
		// if the end of the newInterval is less than the current start,
		// we know that the new interval must be inserted before this interval, regardless of the current end
		if (en_index < 0 && e < curr_start)
			en_index = i;

		// Note: we are keeping track of the starting and ending index to place our new interval. 
		// Also note that we only want to keep track of the first starting and ending index, 
		// so we ignore the computation in the loop once we have found the first starting and ending index
	}

	// if both the starting and ending index are -1, this means that the new interval must be inserted at the end
	if (en_index < 0 && st_index < 0) {
		intervals.push_back(newInterval);
		return intervals;
	}

	// in case our loop does not find an ending index, we know that the ending index must be the last index
	if (en_index < 0)
		en_index = n;

	// this will insert and delete the unwanted intervals
	helper(intervals, newInterval, st_index, en_index);

	return intervals;
}

int main(){
	vector<vector<int>> intervals = {{1,3},{6,9}};
	vector<int> newInterval = {2,5};

	vector<vector<int>> ans = insert(intervals, newInterval);
	for (auto i : ans) {
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	return 0;
}