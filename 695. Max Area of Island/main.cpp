#include<iostream>
#include<vector>
using namespace std;

int helper(vector<vector<int>>& grid, int r, int c, int n) {
    if (r < 0 || c < 0 || r > grid.size() || c > grid[0].size())
        return 0;
    
    if (grid[r][c] == 1){
        n++;
        grid[r][c] = 0;
    }
    
    if (r - 1 >= 0 && grid[r - 1][c] != 0)
        n = helper(grid, r - 1, c, n);
    if (r + 1 < grid.size() && grid[r + 1][c] != 0)
        n = helper(grid, r+1, c, n);
    if (c - 1 >= 0 && grid[r][c - 1] != 0)
        n = helper(grid, r, c - 1, n);
    if (c + 1 < grid[0].size() && grid[r][c + 1] != 0)
        n = helper(grid, r, c + 1, n);
    
    return n;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int mx = INT_MIN;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] != 1)
                continue;
            
            
            mx = max(mx, helper(grid, i, j, 0));
        }
    }
    
    return max(mx, 0);
}

int main(){

    return 0;
}