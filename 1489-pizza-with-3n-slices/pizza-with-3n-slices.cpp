class Solution {
public:
    int solve(int i, int k, int end, vector<vector<int>>&dp,vector<int>&slices){
        if(k==0) return 0;
        if(i>end) return -1e9;
        if(dp[i][k]!=-1) return dp[i][k];
      //  int pick=0;
        int pick = slices[i] + solve(i+2,k-1,end,dp,slices);
        int not_pick = solve(i+1,k,end,dp,slices);
        return dp[i][k] = max(pick,not_pick);
    }
    int maxSizeSlices(vector<int>& slices) {
        int m = slices.size();
        int n = m/3;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans = solve(0,n,m-2,dp,slices);
        vector<vector<int>>dp1(m+1,vector<int>(n+1,-1));
        int ans1 = solve(1,n,m-1,dp1,slices);
        return max(ans,ans1);
    }
};