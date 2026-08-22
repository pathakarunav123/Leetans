class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&dp,string &s){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j] = solve(i+1,j-1,dp,s);
        return dp[i][j] = min(1+solve(i+1,j,dp,s),1+solve(i,j-1,dp,s));

    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans = solve(0,n-1,dp,s);
        return ans;
    }
};