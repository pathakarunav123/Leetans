class Solution {
public:
    int solve(int i, int k, vector<vector<int>>&dp,vector<vector<int>>&events){
        int n = events.size();
        if(i==n) return 0;
        if(k==0) return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        int not_take = solve(i+1,k,dp,events);
        auto it = upper_bound(events.begin(),events.end(),events[i][1],
        [](int end ,const vector<int>& event){
            return end<event[0];
        }
        );
        int j = it-events.begin();
        int take = events[i][2]+solve(j,k-1,dp,events);
        return dp[i][k]=max(take,not_take);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        int k =2;
        sort(events.begin(),events.end());
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        int ans = solve(0,2,dp,events);
        return ans;
    }
};