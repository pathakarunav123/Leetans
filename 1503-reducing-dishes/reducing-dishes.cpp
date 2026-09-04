class Solution {
public:
    int solve(int i, int j, vector<vector<long long>>&dp, vector<int>&satisfaction){
        int n = satisfaction.size();
        if(i==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long pick = j*satisfaction[i] + solve(i+1,j+1,dp,satisfaction);
        long long not_pick = solve(i+1,j,dp,satisfaction);
        return dp[i][j] = max(pick,not_pick);

    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));
        int ans = solve(0,1,dp,satisfaction);
        return ans;
    }
};