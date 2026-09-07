class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&dp, vector<int>&nums){
        if(j==i+1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = -1e9;
        for(int k=i+1; k<j; k++){
            ans = max(ans,solve(i,k,dp,nums)+solve(k,j,dp,nums)+nums[i]*nums[k]*nums[j]);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
         nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans = solve(0,n-1,dp,nums);
        return ans;
    }
};