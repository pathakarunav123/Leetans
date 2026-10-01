class Solution {
public:
    int solve(int i, vector<vector<int>>&dp, vector<int>&nums, int k){
        if(k==0){
            if(i==nums.size()){
                return 0;
            }
            return 1e9;
        }
        if(dp[i][k]!=-1) return dp[i][k];
        int maxi = -1e9;
        int sum =0;
         int ans = 1e9;    
        for(int j=i; j<nums.size();j++){
             sum+=nums[j];
          maxi = max(sum, solve(j+1,dp,nums,k-1));
          ans = min(ans,maxi);
        }   
        return dp[i][k]=ans;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        int ans = solve(0,dp,nums,k);
        return ans;
    }
};