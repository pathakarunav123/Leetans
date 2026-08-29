class Solution {
public:
    const int MOD = 1e9+7;
     const int OFFSET = 1000;
    int solve(int i,int k,vector<vector<int>>&dp,int &arrLen){
        if(k==0){
            return (i==0);
        }
        if(i<0 || i>=arrLen) return 0;
        if(dp[i+OFFSET][k]!=-1) return dp[i+OFFSET][k];
        
        int  left = solve(i-1,k-1,dp,arrLen);
        
        int right = solve(i+1,k-1,dp,arrLen);
        int stay = solve(i,k-1,dp,arrLen);
        int ans = ((long long)left+right+stay)%MOD;

        return dp[i+OFFSET][k]=ans;

    }

    int numWays(int steps, int arrLen) {
      //  int maxPos = max(arrlen,step+1);
        vector<vector<int>>dp(3001,vector<int>(steps+1,-1));
        int ans = solve(0,steps,dp,arrLen);
        return ans;
        
    }
};