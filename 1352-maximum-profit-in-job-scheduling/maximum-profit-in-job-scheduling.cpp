class Solution {
public:
        int solve(int i, vector<int>&dp, vector<vector<int>>&job){
            int n = job.size();
            if(i==n) return 0;
            if(dp[i]!=-1)return dp[i];
            int skip = solve(i+1,dp,job);
            auto it = lower_bound(job.begin(),job.end(),job[i][1]
            ,[](const vector<int>&start, int end){
                return start[0]<end;
            });
            int j = it-job.begin();
            int take = job[i][2]+solve(j,dp,job);
            return dp[i] = max(skip,take);
        }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>job;
        for(int i=0; i<startTime.size(); i++){
            job.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(job.begin(),job.end(),
        [](vector<int>&a, vector<int>&b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0] < b[0];
        });

       vector<int>dp(n+1,-1);
       int ans = solve(0,dp,job);
       return ans;
    }
};