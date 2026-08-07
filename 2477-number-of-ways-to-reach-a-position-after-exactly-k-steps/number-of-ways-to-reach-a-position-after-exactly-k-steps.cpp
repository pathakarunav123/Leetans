class Solution {
public:
    const int MOD = 1e9+7;
    const int OFFSET = 1000;
    int solve(int startPos,int endPos, int k, vector<vector<int>>&dp){
        if(k==0) return (startPos==endPos);
        if(dp[startPos+OFFSET][k]!=-1) return dp[startPos+OFFSET][k];
        int left = solve(startPos-1,endPos,k-1,dp);
        int right = solve(startPos+1,endPos,k-1,dp);
        int ans = (left+right)%MOD;
        return dp[startPos+OFFSET][k] = ans;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        int dist = abs(startPos-endPos);
        if(dist > k){
        return 0;
        }
        if((k-dist)%2){
        return 0;
        }
        vector<vector<int>>dp(3001,vector<int>(k+1,-1));
        int ans = solve(startPos,endPos,k,dp);
        return ans;
    }
};