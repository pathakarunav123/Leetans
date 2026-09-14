class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&dp, vector<int>&nums1, vector<int>&nums2){
        if(i>=nums1.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take = 1e9;
        int not_take = 1e9;
        if(j==0){
            if(nums1[i]>nums1[i-1] && nums2[i]>nums2[i-1]){
                not_take = solve(i+1,0,dp,nums1,nums2);
            }
            if(nums1[i]>nums2[i-1] && nums2[i]>nums1[i-1]){
              take = 1+solve(i+1,1,dp,nums1,nums2);
            }
        }
             if(j==1){
            if(nums1[i]>nums2[i-1] && nums2[i]>nums1[i-1]){
                not_take = solve(i+1,0,dp,nums1,nums2);
            }
            if(nums1[i]>nums1[i-1] && nums2[i]>nums2[i-1]){
                take = 1+solve(i+1,1,dp,nums1,nums2);
            }
             }
        
        return dp[i][j] = min(take,not_take);

    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        int ans = min(solve(1,0,dp,nums1,nums2),1+solve(1,1,dp,nums1,nums2));
        return ans;
    }
};