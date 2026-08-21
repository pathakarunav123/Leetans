class Solution {
public:
    //int solve(int i, int j, vector<vector<int>>&dp,string &s){
      //  if(i==s.size()|| j<0) return 0;
      //  if(dp[i][j]!=-1) return dp[i][j];
     //   if(s[i]==s[j]){
       //     return dp[i][j] = 1 + solve(i+1,j-1,dp,s);
        //}
        //return dp[i][j] = max(solve(i+1,j,dp,s),solve(i,j-1,dp,s));
    //}
    int longestPalindromeSubseq(string s) {
        int m = s.size();
        vector<vector<int>>dp(m,vector<int>(m,0));
        for(int i=m-1; i>=0; i--){
            dp[i][i]=1;
            for(int j =i+1; j<m; j++){
                if(s[i]==s[j]){
                    dp[i][j] = 2+dp[i+1][j-1];
                }else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        //int ans = solve(0,m-1,dp,s);
        if(s.size()==1) return 1;
        //return ans;
        return dp[0][m-1];
    }
};