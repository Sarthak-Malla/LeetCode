#include <bits/stdc++.h>

using namespace std;

int largestAltitude(vector<int>& gain) {
	int max_ = 0;
	int current = 0;
	for (int height : gain) {
		current += height;
		max_ = max(max_, current);
	}

	return max_;
}

int main(){
	vector<int> gain = {-5, 1, 5, 0, -7};
	cout << largestAltitude(gain) << endl;

	return 0;
}