class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&dp, string &word1, string &word2){
       if(i==word1.size()) return word2.size()-j;
       if(j==word2.size()) return word1.size()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j] = solve(i+1,j+1,dp,word1,word2);
        }
        return dp[i][j] = min({1+solve(i,j+1,dp,word1,word2),1+solve(i+1,j,dp,word1,word2),1+solve(i+1,j+1,dp,word1,word2)});
    }
    int minDistance(string word1, string word2) {
        int n =word1.size();
        int m =word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans = solve(0,0,dp,word1,word2);
        return ans;
    }
};