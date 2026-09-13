class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&dp, string &s){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = solve(i,j-1,dp,s)+1;;
         
        for(int k=i;k<j;k++){
                if( s[k]==s[j]){
                    ans = min(ans,solve(i,k,dp,s)+solve(k+1,j-1,dp,s));
                }
        }
        return dp[i][j]=ans;
    }
    int strangePrinter(string s) {
        int m = s.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        int ans = solve(0,m-1,dp,s);
        return ans;
    }
};