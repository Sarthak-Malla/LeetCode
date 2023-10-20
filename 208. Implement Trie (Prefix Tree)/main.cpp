#include <bits/stdc++.h>

using namespace std;

class Trie {
public:
    vector<string> arr;
    Trie() {
    }
    
    void insert(string word) {
        this->arr.push_back(word);
    }
    
    bool search(string word) {
        for (string w : arr)
            if (w == word)
                return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        for (string word : this->arr) {
            string subword = word.substr(0, prefix.size());

            if (prefix == subword)
                return true;
        }

        return false;
    }
};

int main(){
	Trie* obj = new Trie();
	obj->insert("apple");
	cout << obj->search("apple") << endl;
	cout << obj->search("app") << endl;
	cout << obj->startsWith("app") << endl;
	obj->insert("app");
	cout << obj->search("app") << endl;

	return 0;
}