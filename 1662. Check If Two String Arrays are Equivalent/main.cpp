#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string first = "", second = "";
    for (string word: word1)
        first += word;

    for (string word: word2)
        second += word;
    
    return first == second;
}

int main(){
    vector<string> word1 = {"ab", "c"};
    vector<string> word2 = {"a", "bc"};

    cout<<boolalpha<<arrayStringsAreEqual(word1, word2)<<endl;

    return 0;
}