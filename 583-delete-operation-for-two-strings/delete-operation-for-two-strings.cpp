class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&dp ,string &word1, string &word2){
        if(i==word1.size() || j==word2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j] = 1 +solve(i+1,j+1,dp,word1,word2);
        }
        return dp[i][j] = max(solve(i+1,j,dp,word1,word2),solve(i,j+1,dp,word1,word2));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans = solve(0,0,dp,word1,word2);
        //total deletion
        return (n+m)-2*ans;
    }
};