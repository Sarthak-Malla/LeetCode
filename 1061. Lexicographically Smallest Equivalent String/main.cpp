#include<iostream>
#include<vector>
using namespace std;

vector<int> hash;
int find(int curr) {
    if (hash[curr] == -1)
        return curr;
    
    return hash[curr] = find(hash[curr]);
}
void union_(int x, int y) {
    hash[x] = y;
}
string smallestEquivalentString(string s1, string s2, string baseStr) {
    int len = s1.size();
    hash.resize(26, -1);

    for (int i = 0; i < len; i++) {
        int p1 = find(s1[i] - 'a');
        int p2 = find(s2[i] - 'a');

        if (p1 > p2)
            union_(p1, p2);
        else if (p1 < p2)
            union_(p2, p1);
    }

    int n = baseStr.size();
    for (int i = 0; i < n; i++)
            baseStr[i] = find(baseStr[i] - 'a') + 'a';

    return baseStr;
}

int main(){
    string s1 = "parker", s2 = "morris", baseStr = "parser";
    cout << smallestEquivalentString(s1, s2, baseStr) << endl;

    return 0;
}