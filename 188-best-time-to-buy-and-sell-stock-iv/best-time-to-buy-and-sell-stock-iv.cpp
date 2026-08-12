class Solution {
public:
    int solve(int day,int stock,int k,vector<vector<vector<int>>>&dp,vector<int>&prices){
        if(day==prices.size()) return 0;
        if(k==0) return 0;
        if(dp[day][stock][k]!=-1) return dp[day][stock][k];
        int maxi = -1e9;
        if(stock==0){
            int buy = -prices[day]+solve(day+1,1,k,dp,prices);
            int skip = solve(day+1,0,k,dp,prices);
             maxi = max(buy,skip);
        }else{
            int sell = prices[day] + solve(day+1,0,k-1,dp,prices);
            int skip = solve(day+1,1,k,dp,prices);
             maxi = max(sell,skip);
        }
        return dp[day][stock][k]=maxi;
    }
    int maxProfit(int k, vector<int>& prices) {
        int m = prices.size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(2,vector<int>(k+1,-1)));
        int ans = solve(0,0,k,dp,prices);
        return ans;
    }
};