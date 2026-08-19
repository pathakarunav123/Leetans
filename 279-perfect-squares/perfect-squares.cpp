class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n==0) return 0;
        if(n<0) return 1e9;
        if(dp[n]!=-1) return dp[n];
        int mini = 1e9;
        for(int i=1; i*i<=n; i++){
            int pref_sq = i*i;
            int take=1e9;
            if(n-pref_sq>=0){
             take = solve(n-pref_sq,dp);
            }
            
            mini = min(take+1,mini);
        }
        return dp[n]=mini;
    }
    int numSquares(int n) {
      vector<int>dp(n+1,-1);
        int ans= solve(n,dp);
        if(ans==1e9) return 0;
        return ans;
   
    }
};