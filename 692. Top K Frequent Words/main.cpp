#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<string> topKFrequent(vector<string>& words, int k) {
    map<string, int> hash;
    vector<string> ans(k);

    for (auto word: words) {
        if (hash.find(word) == hash.end())
            hash[word] = 1;
        else
            hash[word]++;
    }

    for (int i = 0; i < k; i++) {
        int max = INT_MIN;
        map<string, int>::iterator a;
        for (auto itr = hash.begin(); itr != hash.end(); itr++) {
            if (itr->second > max) {
                max = itr->second;
                a = itr;
            }
        }
        ans[i] = a->first;

        hash.erase(a);
    }

    return ans;
}

int main(){
    vector<string> words = {"i","love","leetcode","i","love","coding"};
    vector<string> ans = topKFrequent(words, 2);

    for (int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}