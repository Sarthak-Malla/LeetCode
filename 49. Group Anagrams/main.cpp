#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	int n = strs.size();
	unordered_map<string, vector<string>> hash;
	for (int i = 0; i < n; i++) {
		string temp = strs[i];
		sort(temp.begin(), temp.end());
		hash[temp].push_back(strs[i]);
	}

	vector<vector<string>> ans;
	for (auto itr = hash.begin(); itr != hash.end(); itr++) {
		ans.push_back(itr->second);
	}

	return ans;
}

int main(){
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> ans = groupAnagrams(strs);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}