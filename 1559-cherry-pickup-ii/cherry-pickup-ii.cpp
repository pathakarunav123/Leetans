class Solution {
public:
    int solve(int i,int j,int j1,int m ,int n,vector<vector<vector<int>>>&dp,vector<vector<int>>&grid){
        if(j>=n||j<0 || j1>=n||j1<0) return -1e9;
        int rob1 = grid[i][j];
        int rob2 = grid[i][j1];
        if(i==m-1){
            if(j==j1) return grid[i][j];
            return grid[i][j]+grid[i][j1];
        }
        if(dp[i][j][j1]!=-1) return dp[i][j][j1];
        int collect=0;
        if(j==j1){
            collect+=grid[i][j];
        }else{
            collect+=grid[i][j];
            collect+=grid[i][j1];
        }
        int best = collect + max({solve(i+1,j-1,j1-1,m,n,dp,grid),solve(i+1,j,j1,m,n,dp,grid),solve(i+1,j+1,j1+1,m,n,dp,grid),solve(i+1,j-1,j1,m,n,dp,grid),solve(i+1,j+1,j1,m,n,dp,grid),solve(i+1,j,j1-1,m,n,dp,grid),solve(i+1,j,j1+1,m,n,dp,grid),solve(i+1,j-1,j1+1,m,n,dp,grid),solve(i+1,j+1,j1-1,m,n,dp,grid)});
        return dp[i][j][j1] = best;
    }
    int cherryPickup(vector<vector<int>>& grid) {
       //since they are from same row 
       //1 row 2 col state mein
       int m=grid.size();
       int n =grid[0].size();
       vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
       int ans =solve(0,0,n-1,m,n,dp,grid);
       return max(0,ans);    
    }
};