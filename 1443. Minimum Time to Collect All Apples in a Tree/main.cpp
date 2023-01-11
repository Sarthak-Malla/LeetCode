#include<iostream>
#include<vector>
using namespace std;

int dfs(int curr, int prev, vector<vector<int>>& adjList, vector<bool>& hasApple) {
    int ans = 0;

    for (int idx : adjList[curr]) {
        if (idx != prev) {
            // goes to the end of the graph
            int temp = dfs(idx, curr, adjList, hasApple);

            // checks if the next one had an apple or the current one does
            if (temp || hasApple[idx])
                ans += temp + 2;
        }
    }

    return ans;
}

int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    vector<vector<int>> adjList(n);

    // an adjacency list
    for (auto edge : edges) {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }

    return dfs(0, -1, adjList, hasApple);
}

int main(){
    int n = 4;
    vector<vector<int>> edges = {{0,2},{0,3},{1,2}};
    vector<bool> hasApple = {false,true,false,false};

    cout<<minTime(n, edges, hasApple)<<endl;

    return 0;
}