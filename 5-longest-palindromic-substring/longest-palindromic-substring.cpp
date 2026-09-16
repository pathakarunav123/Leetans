class Solution {
public:
    bool ispal(int i, int j, vector<vector<int>>&dp, string &s){
        if(i==j) return 1;
        if(j==i+1){
            return s[i]==s[j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j] && ispal(i+1,j-1,dp,s)){
            return dp[i][j]= 1;
        }
        return dp[i][j]=0;
    }
    string longestPalindrome(string s) {
        int m = s.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        int i=0;
        int maxLen =0;
        int start = i;
        int j=m-1;
       for(int i=0; i<s.size(); i++){
        for(int j=i; j<m; j++){
            if(ispal(i,j,dp,s)){
              if(j-i+1>maxLen){
                maxLen = max(maxLen,j-i+1);
                start=i;
              }
        }
        }
       }
        return s.substr(start,maxLen);
    }
};