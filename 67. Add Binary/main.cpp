#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
	string ans = "";
	int carry = 0;
	int bleft = b.size() - 1, aleft = a.size() - 1;

	// running a right to left sum
	while (aleft >= 0 && bleft >= 0) {
		int sum = (a[aleft] - '0') + (b[bleft] - '0') + carry;
		if (sum > 2) {
			carry = 1;
			ans = "1" + ans;
		} else if (sum > 1) {
			carry = 1;
			ans = "0" + ans;
		} else {
			carry = 0;
			ans = to_string(sum) + ans;
		}
		aleft--;
		bleft--;
	}

	// if b is longer than a
	while (bleft >= 0) {
		int sum = (b[bleft] - '0') + carry;
		if (sum > 1) {
			carry = 1;
			ans = "0" + ans;
		} else {
			carry = 0;
			ans = to_string(sum) + ans;
		}
		bleft--;
	}

	// if a is longer than b
	while (aleft >= 0) {
		int sum = (a[aleft] - '0') + carry;
		if (sum > 1) {
			carry = 1;
			ans = "0" + ans;
		} else {
			carry = 0;
			ans = to_string(sum) + ans;
		}
		aleft--;
	}

	// if we still have a carry
	if (carry > 0) {
		ans = to_string(carry) + ans;
	}

	return ans;
}

int main(){
	string a = "1010";
	string b = "1011";
	cout << addBinary(a, b) << endl;

	return 0;
}