class Solution {
public:
    int solve(int i, int k,vector<vector<int>>&dp,vector<vector<int>>&events){
        int n = events.size();
        if(k==0) return 0;
        if(i==n) return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        int skip = solve(i+1,k,dp,events);
        auto it = upper_bound(events.begin(),events.end(),events[i][1],
        [](const int &value ,const vector<int>&event){
            return value<event[0];
        });
        int j = it - events.begin();
        int take = events[i][2]+solve(j,k-1,dp,events);
        return dp[i][k]=max(skip,take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(),events.end());
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        int ans = solve(0,k,dp,events);
        return ans;
    }
};