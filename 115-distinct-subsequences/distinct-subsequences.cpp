class Solution {
public:
   // int solve(int i, int j, vector<vector<int>>&dp, string s, string t){
    //    if(j==t.size()) return 1;
    //    if(i==s.size()) return 0;
    //    if(dp[i][j]!=-1)return dp[i][j];
    //    int pick =0;
   //     if(s[i]==t[j]){
   //         return dp[i][j] =solve(i+1,j+1,dp,s,t) + solve(i+1,j,dp,s,t);
   //     }else{
   //       return dp[i][j]= solve(i+1,j,dp,s,t);
   //     }
  //      return dp[i][j];
  //  }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m =t.size();
        vector<vector<unsigned long long>>dp(n+1,vector<unsigned long long>(m+1,0));
        for(int i=0; i<=n; i++){
            dp[i][m] = 1;
        }
        for(int j=0; j<m; j++){
            dp[n][j]=0;
        }
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(s[i]==t[j]){
                    dp[i][j]=dp[i+1][j+1]+dp[i+1][j];
                }else{
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        return dp[0][0];

        //int ans = solve(0,0,dp,s,t);
        //return ans;
    }
};