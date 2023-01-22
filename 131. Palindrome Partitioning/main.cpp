#include <bits/stdc++.h>
using namespace std;

set<vector<string>> ans;
int n;
int len;

// check if the string is palindrome
bool check(string& s) {
	int left = 0;
	int right = s.size() - 1;

	while (left < right) {
		if (s[left] != s[right])
			return false;
		
		left++;
		right--;
	}

	return true;
}

void backTrack(string& s, int start, vector<string>& cur) {
	// the length of the substring is varying in every recursion, so our for loop represents the change in length
	for (int i = 1; i < n - start + 1; i++) {

		// we get the substring from the start index to the length i
		string temp = s.substr(start, i);

		// if the substring is palindrome, we push it into the current vector and call the function recursively
		if (check(temp)) {
			cur.push_back(temp);

			// this recursion will have made a vector of all the palindromes in the string
			backTrack(s, start+i, cur);
		}            
	}

	// we insert the current vector into the set
	if (cur.size() > 0) {
		ans.insert(cur);

		// we pop the last element from the vector to make it not have the last element for the next recursion, such that the first elements are not repeated
		cur.pop_back();
	}

	// this recursion adds every combination to the set
}

vector<vector<string>> partition(string s) {
	n = s.size();
	vector<string> temp;
	backTrack(s, 0, temp);

	vector<vector<string>> res;

	// using a filter to see if the length of all the elements in the vector is equal to the length of the string
	for (auto x : ans) {
		len = 0;
		for (auto y : x)
			len += y.size();
		
		if (len == n)
			res.push_back(x);
	}
	
	return res;
}

int main(){
	string s = "aab";
	vector<vector<string>> res = partition(s);

	for (auto x : res) {
		for (auto y : x)
			cout << y << " ";
		cout << endl;
	}

	return 0;
}