class Solution {
public:
    bool solve(int i, int j, vector<vector<int>>&dp, string &s1, string &s2,string &s3){
        if(i==s1.size() && j==s2.size()){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        if(i<s1.size() && s1[i]==s3[i+j]){
            if(solve(i+1,j,dp,s1,s2,s3)){
                return dp[i][j] =1;
            }
        }
        if(j<s2.size() && s2[j]==s3[i+j]){
            if(solve(i,j+1,dp,s1,s2,s3)){
                return dp[i][j]=1;
            }
        }
        return dp[i][j]=0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n= s1.size();
        int m = s2.size();
        if(n+m != s3.size()) return false;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        bool ans = solve(0,0,dp,s1,s2,s3);
        return ans;
    }
};