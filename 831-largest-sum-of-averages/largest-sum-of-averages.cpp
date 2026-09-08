class Solution {
public:
    double solve(int i, vector<vector<double>>&dp, vector<int>&nums, int k){
        if(i==nums.size()) return 0;
        if(k==0){
            if(i==nums.size()){
                return 0;
            }
            return -1e9;
        }
        if(dp[i][k]!=-1) return dp[i][k];
        double ans = -1e9;
        double sum =0;
        for(int j=i; j<nums.size();j++){
             sum+=nums[j];
             ans = max(ans,sum/(j-i+1) + solve(j+1,dp,nums,k-1));
        }
        return dp[i][k]=ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1));
        double ans = solve(0,dp,nums,k);
        return ans;
    }
};