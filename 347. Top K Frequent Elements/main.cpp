#include <bits/stdc++.h>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> hash;
	for (int num : nums)
		hash[num]++;
	
	vector<int> res;
	priority_queue<pair<int, int>> pq;
	for (auto i = hash.begin(); i != hash.end(); i++)
		pq.push(make_pair(i->second, i->first));
	for (int i = 0; i < k; i++) {
		res.push_back(pq.top().second);
		pq.pop();
	}

	return res;
}

int main(){
	vector<int> nums = {1, 1, 1, 2, 2, 3};
	int k = 2;
	vector<int> res = topKFrequent(nums, k);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}