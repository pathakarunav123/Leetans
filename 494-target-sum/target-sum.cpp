class Solution {
public:
    int solve(int i, int p, vector<vector<int>>&dp, vector<int>&nums){
        if(i==nums.size()){
            return (p==0);
        }
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i][p]!=-1){
            return dp[i][p];
        }
        int take = 0;
        if(nums[i]<=p){
            take = solve(i+1,p-nums[i],dp,nums);
        }
        int not_take = solve(i+1,p,dp,nums);
        return dp[i][p]=take + not_take;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int p =0;
        int totalsum = 0;
        for(int i=0; i<nums.size(); i++){
            totalsum +=nums[i];
        }
        if(totalsum<abs(target)){
            return 0;
        }
        if(((target + totalsum) & 1)!=0){
            return 0;
        }
        p = (target+totalsum)/2;
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(p+1,-1));
        int ans = solve(0,p,dp,nums);
        return ans;
    }
};