class Solution {
public:
    int MOD = 1e9+7;
    int solve(int i,vector<int>&dp, int low, int high, int zero, int one){
        if(i==high)return 1;
        if(i>high)return 0;
        if(dp[i]!=-1)return dp[i];
        int ways = 0;
        int one_time = solve(i+one,dp,low,high,zero,one);
        int zero_time = solve(i+zero,dp,low,high,zero,one);
        if(i>=low){
            ways=1;
        }
        return dp[i]=(zero_time+one_time+ways)%MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,-1);
        int ans = solve(0,dp,low,high,zero,one);
        return ans;
    }
};