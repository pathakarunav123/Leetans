class Solution {
public:
  bool isPal(int i, int j, vector<vector<int>>&dp1,string &s){
    if(i==j) return 1;
    if(j==i+1){
        return (s[i]==s[j]);
    }
    if(dp1[i][j]!=-1) return dp1[i][j];
    if(s[i]==s[j] && isPal(i+1,j-1,dp1,s)){
        return dp1[i][j]=1;
    }
    return dp1[i][j]=0;
  }
   bool solve(int i, int k, vector<vector<int>>&dp,vector<vector<int>>&dp1,string &s){
        if(k==0){
            return (i==s.size());
        }
    
    if(dp[i][k]!=-1)return dp[i][k];
    for(int j=i; j<s.size(); j++){
        if(isPal(i,j,dp1,s)){
            if(solve(j+1,k-1,dp,dp1,s)){
                return dp[i][k]=1;
            }
        }
    }
    return dp[i][k]=0;
   }
    bool checkPartitioning(string s) {
        int n =s.size();
        int k =3;
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        vector<vector<int>>dp1(n+1,vector<int>(n+1,-1));
        bool ans = solve(0,k,dp,dp1,s);
        return ans;
    }
};