#include<iostream>
#include<vector>
using namespace std;

// bool satisfy(vector<vector<int>>& grid) {
//     int i, j;
//     for (i = 0; i < grid.size(); i++) {
//         for (j = 0; j < grid[0].size(); j++) {
//             if (grid[i][j] == 0)
//                 return false;
//         }
//     }

//     return true;
// }

int helper(vector<vector<int>>& grid, int i, int j, int count, int zero) {
    // if you find the ending check if all the squares are walked over
    if (grid[i][j] == 2) {
        if (zero == -1) 
            count++;
        return count;
    }
    
    grid[i][j] = -1;

    if (i + 1 < grid.size() && grid[i+1][j] != -1)
        count = helper(grid, i+1, j, count, zero - 1);
    if (i - 1 >= 0 && grid[i-1][j] != -1)
        count = helper(grid, i-1, j, count, zero - 1);
    if (j + 1 < grid[0].size() && grid[i][j+1] != -1)
        count = helper(grid, i, j+1, count, zero - 1);
    if (j - 1 >= 0 && grid[i][j-1] != -1)
        count = helper(grid, i, j-1, count, zero - 1);
    
    // backtracking
    grid[i][j] = 0;

    return count;
}

int uniquePathsIII(vector<vector<int>>& grid) {
    // looking for the starting point
    int x, y, zero = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                x = i;
                y = j;
            }
            if (grid[i][j] == 0)
                zero++;
        }
    }

    // attempt at a dfs solution
    return helper(grid, x, y, 0, zero);
}

int main(){
    vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    cout << uniquePathsIII(grid) << endl;

    return 0;
}