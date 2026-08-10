class Solution {
public:
    int solve(int i1, int i2, int t, int m,vector<vector<vector<int>>>&dp,vector<vector<int>>&grid){
        int j1 = t-i1;
        int j2 = t-i2;
        if(i1>=m||i2>=m||j1>=m||j2>=m||grid[i1][j1]==-1||grid[i2][j2]==-1)return -1e9;
        if((i1==m-1 && j1==m-1) || (i2==m-1 && j2==m-1)) return grid[m-1][m-1];
        if(dp[i1][i2][t]!=-1) return dp[i1][i2][t];
        int collect = 0;
        if(i1==i2){
            collect+=grid[i1][j1];
        }else{
            collect+=grid[i1][j1];
            collect+=grid[i2][j2];
        }
        int best = collect + max({solve(i1+1,i2+1,t+1,m,dp,grid),solve(i1+1,i2,t+1,m,dp,grid),solve(i1,i2+1,t+1,m,dp,grid),solve(i1,i2,t+1,m,dp,grid)});
       return dp[i1][i2][t] = best;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(m+1,vector<int>(2*m+1,-1)));
        //i+j=t
        //j = t-i;
        //taking two person traversing together i1,i2, and taking t step to reach bottom right
        ///thereFore the state will form
        int ans = solve(0,0,0,m,dp,grid);
        return max(0,ans);
    }
};