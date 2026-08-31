class Solution {
public:
    int MOD = 1e9+7;
    int solve(vector<vector<long long>>&dp,int n, int k, int target){
        if(target<0) return 0;
        if(n==0){
            return (target==0);
        }
        int ans =0;
        if(dp[n][target]!=-1) return dp[n][target];
        for(int roll=1; roll<=k; roll++){
            ans += solve(dp,n-1,k,target-roll);
            ans%=MOD;

        }
        return dp[n][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>>dp(n+1,vector<long long>(target+1,-1));
        long long ans = solve(dp,n,k,target);
        return ans;
    }
};