class Solution {
public:
   // int solve(int i, int j, vector<vector<int>>&dp,vector<int>&nums1,vector<int>&nums2){
   //     if(i==nums1.size() || j==nums2.size()) return 0;
   //     if(dp[i][j]!=-1) return dp[i][j];
   //     if(nums1[i]==nums2[j]) return dp[i][j] = 1+solve(i+1,j+1,dp,nums1,nums2);
   //     return dp[i][j] = max(solve(i+1,j,dp,nums1,nums2),solve(i,j+1,dp,nums1,nums2));
   // }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n-1; i>=0; i--){
            for(int j =m-1; j>=0; j--){
                if(nums1[i]==nums2[j]){
                    dp[i][j] = 1+dp[i+1][j+1];
                }else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }

        return dp[0][0];

        //int ans = solve(0,0,dp,nums1,nums2);
       // return ans;
    }
};