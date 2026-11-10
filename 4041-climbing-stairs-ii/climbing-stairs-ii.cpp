class Solution {
public:
    int solve(int i, vector<int>&dp, vector<int>&cost,int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int x =((i+1)-i);
        int ans = cost[i]+x*x+solve(i+1,dp,cost,n);
        x = ((i+2)-i);
        if(i+1<n){
            ans = min(ans,cost[i+1]+x*x+solve(i+2,dp,cost,n));
        }
        x=((i+3)-i);
        if(i+2<n){
            ans = min(ans,cost[i+2]+x*x+solve(i+3,dp,cost,n));

        }
        return dp[i]=ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,-1);
        int ans = solve(0,dp,costs,n);
        return ans;
    }
};