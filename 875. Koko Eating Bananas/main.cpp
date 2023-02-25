#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
	sort(piles.begin(), piles.end());
	int l = 1, r = piles[piles.size() - 1];

	while (l < r) {
		int k = (l + r)/2;
		int hours = 0;
		for (int p : piles)
			hours += ((p+k-1)/k);
		
		if (hours > h)
			l = k + 1;
		else
			r = k;
	}

	return l;
}

int main(){
	vector<int> piles = {3,6,7,11};
	int h = 8;
	cout << minEatingSpeed(piles, h) << endl;

	return 0;
}