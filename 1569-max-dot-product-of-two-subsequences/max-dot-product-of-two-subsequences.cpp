class Solution {
public:
   // int solve(int i, int j,vector<vector<int>>&dp,vector<int>&nums1,vector<int>&nums2){
   //     if(i==nums1.size() || j==nums2.size()) return -1e9;
   //     if(dp[i][j]!=-1) return dp[i][j];
   //     return dp[i][j] = max({nums1[i]*nums2[j],nums1[i]*nums2[j]+solve(i+1,j+1,dp,nums1,nums2),solve(i+1,j,dp,nums1,nums2),solve(i,j+1,dp,nums1,nums2)});
  //  }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1e9));
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                dp[i][j] = max({nums1[i]*nums2[j],nums1[i]*nums2[j]+dp[i+1][j+1],dp[i+1][j],dp[i][j+1]});
            }

        }
        return dp[0][0];
       // int ans = solve(0,0,dp,nums1,nums2);
        //return ans;
    }
};