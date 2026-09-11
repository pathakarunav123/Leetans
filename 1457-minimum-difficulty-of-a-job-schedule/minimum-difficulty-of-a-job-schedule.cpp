class Solution {
public: 
    int solve(int i,int d, vector<vector<int>>&dp, vector<int>&jobDifficulty){
        int n = jobDifficulty.size();
        if(d==0){
            if(i==n){
                return 0;
            }else{
                return 1e9;
            }
        }
        if(dp[i][d]!=-1) return dp[i][d];
        int ans = 1e9;
        int max_diff =-1e9;
        for(int j=i; j<n; j++){
            max_diff = max(max_diff,jobDifficulty[j]);
            ans = min(ans,max_diff+solve(j+1,d-1,dp,jobDifficulty));
        }
        return dp[i][d] = ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n<d) return -1;
        vector<vector<int>>dp(n+1,vector<int>(d+1,-1));
        int ans = solve(0,d,dp,jobDifficulty);
        return ans;
    }
};