class Solution {
public:
    int solve(int i,vector<int>&dp, vector<vector<int>>&offers){
        if(i==offers.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int skip = solve(i+1,dp,offers);
        auto it = upper_bound(offers.begin(),offers.end(),offers[i][1],
            [](const int end, const vector<int>start){
                return start[0]>end;
            });
            int j = it-offers.begin();
            int take = offers[i][2]+solve(j,dp,offers);
            return dp[i]=max(skip,take);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int m = offers.size();
        sort(offers.begin(),offers.end());
        vector<int>dp(m+1,-1);
        int ans = solve(0,dp,offers);
        return ans;
    }
};