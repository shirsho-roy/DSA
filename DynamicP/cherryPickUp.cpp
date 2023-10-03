#include<bits/stdc++.h> 
using namespace std;
int rows, cols;
int cherryPickup(vector<vector<int>>& grid) {
        rows = (int)grid.size();
        cols = (int)grid[0].size();

        // initializing a 3D array dp
        vector<vector<vector<int>>> dp(rows, vector<vector<int>> (cols, vector<int>(cols, -1)));
        int ans = solve(dp, 0, 0, cols - 1, grid);
        return ans;
    }


    int solve(vector<vector<vector<int>>> &dp, int r, int c1, int c2, vector<vector<int>> &grid) {
        if(r >= rows) return 0;
        if(c1 < 0 or c2 < 0 or c1 >= cols or c2 >= cols or c1 > c2) return 0; 
        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];

        int cur= grid[r][c1];
        if(c1 != c2) cur+= grid[r][c2];

        int mx = 0;
        mx = max({mx, solve(dp, r + 1, c1, c2, grid), 
solve(dp, r + 1, c1, c2 - 1, grid), solve(dp, r + 1, c1 + 1, c2 - 1, grid), 
solve(dp, r + 1, c1 + 1, c2, grid)});

        if(c1)
            mx= max({mx, solve(dp, r + 1, c1 - 1, c2, grid), 
solve(dp, r+1, c1-1, c2-1, grid)});

        if(c2 + 1 < cols)
            mx= max({mx, solve(dp, r + 1, c1, c2 + 1, grid), 
solve(dp, r + 1, c1 + 1, c2 + 1, grid)});

        if(c1 and c2 + 1 < cols)
            mx= max(mx, solve(dp, r + 1, c1 - 1, c2 + 1, grid));


        return dp[r][c1][c2] = mx + cur;
    }
int main(){
    
}