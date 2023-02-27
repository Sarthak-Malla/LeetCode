#include <bits/stdc++.h>
using namespace std;

int numDecodings(string s) {
	int n = s.size();
	vector<int> dp(n+1, 0);
	dp[n] = 1;

	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '0')
			dp[i] = 0;
		else
			dp[i] = dp[i + 1];
		
		if (i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')))
			dp[i] += dp[i + 2];
	}

	return dp[0];
}

int main(){
	string s;
	cin >> s;
	cout << numDecodings(s) << endl;

	return 0;
}