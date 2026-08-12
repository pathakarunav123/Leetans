class Solution {
public:
    int solve(int day,int stock,vector<vector<int>>&dp,vector<int>&prices){
        if(day>=prices.size())return 0;
        if(dp[day][stock]!=-1)return dp[day][stock];
        int maxi = -1e9;
        if(stock==0){
            int buy = -prices[day] + solve(day+1,1,dp,prices);
            int skip = solve(day+1,0,dp,prices);
            maxi = max(buy,skip);
        }else{
            int sell = prices[day] + solve(day+2,0,dp,prices);
            int skip = solve(day+1,1,dp,prices);
            maxi=max(sell,skip);
        }
        return dp[day][stock]=maxi;
    }
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        vector<vector<int>>dp(m+1,vector<int>(2,-1));
        int ans = solve(0,0,dp,prices);
        return ans;
    }
};