#include <bits/stdc++.h>
using namespace std;

int minFlipsMonoIncr(string s) {
	int n = s.size();

	// to count the number of zeros we have encountered
	int zeros_left = 0;

	// to count the number of ones we have encountered
	int one_left = 0;

	// for total number of zeros
	int zeros = 0;
	int min_ = INT_MAX;

	// counting the total number of zeros
	for (int i = 0; i < n; i++)
		if (s[i] == '0')
			zeros++;

	for (int i = 0; i < n; i++) {
		// calculating the number of zeros on the right
		int zeros_right = zeros - zeros_left;

		// number of zeros on the right is one less when the current character is zero
		if (s[i] == '0')
			zeros_right--;

		// minimum is calculated with the sum of number of ones in the left with the number of zeros on the right
		min_ = min(min_, one_left + zeros_right);

		// calculating the number of ones and zeros we have encountered.
		if (s[i] == '1')
			one_left++;
		else
			zeros_left++;
	}

	return min_;
}

int main(){
	string s = "00110";
	cout << minFlipsMonoIncr(s) << endl;

	return 0;
}