class Solution {
public:
    int solve(int i ,int j, int m, int n, vector<vector<int>>&dp,vector<vector<int>>&grid){
        if(i>=m || j>=n) return 1e9;
        if(i==m-1 && j==n-1)return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down = grid[i][j] + solve(i+1,j,m,n,dp,grid);
         int right =  grid[i][j] + solve(i,j+1,m,n,dp,grid);
        return dp[i][j] = min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans = solve(0,0,m,n,dp,grid);
        return ans;
    }
};