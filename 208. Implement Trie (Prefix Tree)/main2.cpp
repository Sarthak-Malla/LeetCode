#include<iostream>
using namespace std;

class Node {
    public:
    Node* children[26];
    bool wordEnd = false;
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = this->root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (curr->children[word[i] - 'a'] == nullptr)
                curr->children[word[i] - 'a'] = new Node();
            curr = curr->children[word[i] - 'a'];
        }
        curr->wordEnd = true;
    }
    
    bool search(string word, bool prefix = false) {
        Node* curr = this->root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (curr->children[word[i] - 'a'] == nullptr)
                return false;
            curr = curr->children[word[i] - 'a'];
        }
        if (prefix == false) return curr->wordEnd;
        return true;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

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