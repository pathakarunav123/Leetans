class Solution {
public:
    bool solve(int i, int j,vector<vector<int>>&dp, string &s, vector<string>&wordDict){
        if(i==s.size()) return 1;
        if(j>=s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int d=0; d<wordDict.size(); d++){
             string x = s.substr(i,j-i+1);
            if(x==wordDict[d]){
                if(solve(j+1,j+1,dp,s,wordDict)){
                    return dp[i][j]=1;
                }
            }
         if(solve(i, j+1, dp, s, wordDict)){
        return dp[i][j] = true;
         }
        }
        return dp[i][j]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        bool ans = solve(0,0,dp,s,wordDict);
        return ans;
    }
};