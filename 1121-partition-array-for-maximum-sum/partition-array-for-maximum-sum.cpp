class Solution {
public:
    int solve(int i,vector<int>&dp,vector<int>&arr,int k){
        if(i==arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = -1e9;
        int mx = -1e9;
        for(int j=i; j<arr.size(); j++){
             mx = max(mx,arr[j]);
            if(j-i+1<=k){
                ans = max(ans,mx*(j-i+1)+solve(j+1,dp,arr,k));
            }
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,-1);
        int ans = solve(0,dp,arr,k);
        return ans;
    }
};