class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp, string &s1, string &s2){
        if(i==s1.size() || j==s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j])  return dp[i][j]= s1[i]+solve(i+1,j+1,dp,s1,s2);
        return dp[i][j] = max(solve(i+1,j,dp,s1,s2),solve(i,j+1,dp,s1,s2));
    }
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ascii_sum_1 = 0;
        int ascii_sum_2 = 0;
        for(int i=0; i<m; i++){
            ascii_sum_1 +=s1[i];
        }
        for(int i=0; i<n; i++){
            ascii_sum_2 +=s2[i];
        }
        int ascii_lcs = solve(0,0,dp,s1,s2);
        return (ascii_sum_1+ascii_sum_2) - 2*(ascii_lcs);
    }
};