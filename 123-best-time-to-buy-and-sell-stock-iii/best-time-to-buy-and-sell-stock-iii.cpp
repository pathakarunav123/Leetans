class Solution {
public:
    int solve(int day,int stock,int t,vector<vector<vector<int>>>&dp,vector<int>& prices){
        if(day>=prices.size()) return 0;
        if(t==2) return 0;
        if(dp[day][stock][t]!=-1)return dp[day][stock][t];
        int maxi = -1e9;
        if(stock==0){
            int buy = -prices[day] + solve(day+1,1,t,dp,prices);
            int skip = solve(day+1,0,t,dp,prices);
            maxi = max(buy,skip);
        }else{
            int sell = prices[day] + solve(day+1,0,t+1,dp,prices);
            int skip = solve(day+1,1,t,dp,prices);
            maxi = max(sell,skip);
        }
        return dp[day][stock][t] = maxi;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int total_transaction=2;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(total_transaction+1,-1)));
        int ans = solve(0,0,0,dp,prices);
        return ans;    
    }
};