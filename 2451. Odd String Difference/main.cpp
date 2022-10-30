#include<iostream>
#include<vector>
using namespace std;

string oddString(vector<string>& words) {
    vector<vector<int>> difference(words.size(), vector<int> (words.size() - 1));
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words[0].size() - 1; j++) {
            difference[i][j] = words[i][j+1] - words[i][j];
        }
    }
    
    vector<int> curr = difference[0];
    int diff = 0;
    int count = 0;
    for (int i = 1; i < difference.size(); i++) {
        for (int j = 0; j < difference[i].size(); j++) {
            if (curr[j] != difference[i][j]) {
                diff = i;
                count++;
                break;
            }
        }
    }
    
    if (count > 1)
        diff = 0;
    
    return words[diff];
    
}

int main(){
    vector<string> words = {"adc","wzy","abc"};

    cout<<oddString(words)<<endl;

    return 0;
}