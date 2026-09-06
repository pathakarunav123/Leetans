class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&dp,int n){
        if(i==n) return 0;
         if(i>n) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int copy_all = 1e9;
        if(i!=j){
         copy_all = 1+solve(i,i,dp,n);
        }
        int paste = 1e9;
        if(j>0){
        paste = 1+solve(i+j,j,dp,n);
        }
        return dp[i][j] = min(copy_all,paste);
    }
    int minSteps(int n) {
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        int ans = solve(1,0,dp,n);
        return ans;        
    }
};