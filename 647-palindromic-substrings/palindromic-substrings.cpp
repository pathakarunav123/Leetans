class Solution {
public:
        bool isPal(int i, int j, vector<vector<int>>&dp1,string &s){
            if(i==j) return 1;
            if(j==i+1){
                return s[i]==s[j];
            }
            if(dp1[i][j]!=-1)return dp1[i][j];
            if(s[i]==s[j]&&isPal(i+1,j-1,dp1,s)) return dp1[i][j]=1;
            return dp1[i][j]=0;
        }
    int solve(int i, vector<int>&dp,vector<vector<int>>&dp1,string &s){
        if(i==s.size())return 0;
        if(dp[i]!=-1) return dp[i];
        int ans =solve(i + 1, dp, dp1, s);;
        for(int j=i; j<s.size(); j++){
            if(isPal(i,j,dp1,s)){
                ans+=1;
            }
        }
        return dp[i]=ans;
    }
    int countSubstrings(string s) {
        int n = s.size();
        vector<int>dp1(n+1,-1);
        vector<vector<int>>dp2(n+1,vector<int>(n+1,-1));
        int ans = solve(0,dp1,dp2,s);
        return ans;
    }
};