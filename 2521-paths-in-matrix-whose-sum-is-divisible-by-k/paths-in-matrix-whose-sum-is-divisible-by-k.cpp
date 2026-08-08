class Solution {
public:
    const int MOD=1e9+7;
    int solve(int i,int j,int currsum,int m,int n,vector<vector<vector<int>>>&dp,vector<vector<int>>&grid,int k){
        if(i>=m || j>=n)return 0;
        if(i==m-1&&j==n-1){
            if((currsum+grid[i][j])%k==0){
                return 1;
            }else{
                return 0;
            }
        }
        if(dp[i][j][currsum%k]!=-1)return dp[i][j][currsum%k];

     
        int down= solve(i+1,j,currsum+grid[i][j],m,n,dp,grid,k);
        int right = solve(i,j+1,currsum+grid[i][j],m,n,dp,grid,k);
        int comb = (down+right)%MOD;
        return dp[i][j][currsum%k]=comb;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n =grid[0].size();
       vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k,-1)));
        int ans = solve(0,0,0,m,n,dp,grid,k);
        return ans;
    }
};