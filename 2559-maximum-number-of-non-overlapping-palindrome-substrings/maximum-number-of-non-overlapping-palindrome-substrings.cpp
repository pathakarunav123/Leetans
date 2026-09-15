class Solution {
public:
        bool isPal(int i, int j, vector<vector<int>>&dp1,string &s){
            if(j==i+1) return (s[i]==s[j]);
            if(i==j) return 1;
            if(dp1[i][j]!=-1) return dp1[i][j];
            if(s[i]==s[j]){
                if(isPal(i+1,j-1,dp1,s)){
                   return dp1[i][j]=1;
                }
            }
            return dp1[i][j]=0;
        }
        int solve(int i, vector<int>&dp,vector<vector<int>>&dp1,string&s, int k){
            if(i==s.size()) return 0;
            if(dp[i]!=-1) return dp[i];
            int ans =solve(i+1,dp,dp1,s,k);
            for(int j=i+k-1; j<s.size(); j++){
                if(isPal(i,j,dp1,s)){
                    ans = max(ans,1+solve(j+1,dp,dp1,s,k));
                }
            }
           return dp[i] = ans;
        }
    int maxPalindromes(string s, int k) {
        int m = s.size();
        vector<int>dp(m+1,-1);
        vector<vector<int>>dp1(m+1,vector<int>(m+1,-1));
        int ans = solve(0,dp,dp1,s,k);
        return ans;
    }
};