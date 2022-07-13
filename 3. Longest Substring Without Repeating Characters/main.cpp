#include<iostream>
#include<string>
#include<vector>
#include<iterator>
using namespace std;

int lengthOfLongestSubstring(string s){

    // To record the characters we have seen
    vector<char> seen;
    vector<char>::iterator itr;

    // len: current length of unique substring
    // longest: the longest of all substrings
    int len = 0, longest = 0;

    for (int i = 0; i < s.length(); i++){
        // Searching for the char in the seen vector.
        vector<char>::iterator elem = find(seen.begin(), seen.end(), s[i]);

        // If the character is not there we increas the length by 1
        // else we delete every character that came before the CHAR including itself: In this we decrese the length of the substring by the number of characters deleted.
        if (elem == seen.end()){
            len++;
        } else {
            int idx = elem - seen.begin();
            
            for (int j = 0; j <= idx; j++){
                seen.erase(seen.begin());
            }

            len -= idx;
        }
        
        // getting the longest
        if (len > longest)
            longest = len;

        // adding to seen
        seen.push_back(s[i]);
    }

    return longest;
}

int main(){
    string s = "aab";

    int length = lengthOfLongestSubstring(s);

    cout<<length<<endl;
    return 0;
}