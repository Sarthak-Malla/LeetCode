#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<int>& hash, const string& labels, vector<int>& ans, vector<vector<int>>& adjList, int prev, int curr) {
    // this count the frequency from top to bottom
    int prevCount = hash[labels[curr] - 'a'];

    hash[labels[curr] - 'a']++;

    // dfs
    for (int idx : adjList[curr]) {
        if (idx == prev)
            continue;
        dfs(hash, labels, ans, adjList, curr, idx);
    }

    // deleting frequency from top
    ans[curr] = hash[labels[curr] - 'a'] - prevCount;
}

vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    vector<int> ans(n, 0);
    vector<vector<int>> adjList(n);
    vector<int> hash(26, 0);

    int len = edges.size();
    for (auto edge : edges) {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }

    dfs(hash, labels, ans, adjList, -1, 0);

    return ans;
}

int main(){
    int n = 7;
    vector<vector<int>> edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    string labels = "abaedcd";
    vector<int> ans = countSubTrees(n, edges, labels);
    for (int i : ans)
        cout << i << " ";
    cout<<endl;

    return 0;
}