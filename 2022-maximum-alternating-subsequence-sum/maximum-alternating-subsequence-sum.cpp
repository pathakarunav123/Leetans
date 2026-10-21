class Solution {
public:
    long long solve(long long i, long long j, vector<vector<long long>>&dp, vector<int>&nums){
        int n = nums.size();
        if(i==n){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        
        long long take = 0;
        long long skip =0;
        
        if(j==0){
          take = 1LL*nums[i]+solve(i+1,1,dp,nums);
           skip  = solve(i+1,0,dp,nums);
        }
        if(j==1){
           take = -1LL*nums[i]+solve(i+1,0,dp,nums);
           skip = solve(i+1,1,dp,nums);
        }
        return dp[i][j] = max(take,skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>>dp(n+1,vector<long long>(3,-1));
        long long ans = solve(0,0,dp,nums);
        return ans;
    }
};