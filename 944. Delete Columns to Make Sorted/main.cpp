#include<iostream>
#include<vector>
using namespace std;

int minDeletionSize(vector<string>& strs) {
    // number of words
    int words = strs.size();

    // length of each word
    int word = strs[0].size();

    int j;

    // stores the number of deletions
    int ans = 0;

    // i iterates over each character in each word
    for (int i = 0; i < word; i++) {

        // c is the current character
        char c = strs[0][i];

        // j iterates over each word
        for (j = 1; j < words; j++) {

            // checks if the current character is lexically less than the next character
            if (strs[j][i] < c)
                break;

            // updates the current character
            c = strs[j][i];
        }

        // if j is equal to words, then it did not break out of the loop, meaning that the charactes are lexically sorted
        if (j != words)
            ans++;
    }

    return ans;
}

int main(){

    return 0;
}