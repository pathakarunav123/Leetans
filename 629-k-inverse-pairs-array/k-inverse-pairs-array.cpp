class Solution {
public:
    int MOD = 1e9+7;
    int solve(int i, int j, vector<vector<int>>&dp){
        if(i==0){
            if(j==0) return 1;
            return 0;
        }
        if(j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long a = solve(i-1,j,dp);
        long long b= solve(i,j-1,dp);
        long long c =0;
        if(j-i>=0){
            c=solve(i-1,j-i,dp);
        }else{
            c=0;
        }
        long long ans=(a+b-c+MOD)%MOD;
        return dp[i][j]=ans%MOD;
    }
    int kInversePairs(int n, int k) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        long long ans = solve(n,k,dp);
        return ans;
    }
};