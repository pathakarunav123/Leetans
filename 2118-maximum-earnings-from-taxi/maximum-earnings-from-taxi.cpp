class Solution {
public:
    long long solve(int i, vector<long long>&dp, vector<vector<int>>&rides){
        int n = rides.size();
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        long long skip = solve(i+1,dp,rides);
        auto it = lower_bound(rides.begin(), rides.end(),rides[i][1],
        [](const vector<int>elem, const auto value){
            return elem[0]<value;
        });
        int j = it-rides.begin();
        long long take = (rides[i][1]-rides[i][0]+rides[i][2])+solve(j,dp,rides);
        return dp[i]=max(take,skip);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int m = rides.size();
        sort(rides.begin(),rides.end());
        vector<long long>dp(m+1,-1);
        long long ans = solve(0,dp,rides);
        return ans;
    }
};