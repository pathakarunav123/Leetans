class Solution {
public:
    bool isPal(int i, int j, vector<vector<int>>&pal, string &s){
        if(i==j) return 1;
        if(j==i+1){
            return (s[i]==s[j]);
        }
        if(pal[i][j]!=-1) return pal[i][j];
        if(s[i]==s[j] && isPal(i+1,j-1,pal,s)){
            return pal[i][j] = 1;
        }
        return pal[i][j]=0;
    }
    int solve(int i, vector<int>&dp,vector<vector<int>>&pal,string &s){
        if(i==s.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = 1e9;
        for(int j=i; j<s.size(); j++){
            if(isPal(i,j,pal,s)){
               if(j==s.size()-1){
                ans =0;
               }else{
                ans = min(ans,1+solve(j+1,dp,pal,s));
               }
            }
           
        }
        return dp[i] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n+1,-1);
        vector<vector<int>>pal(n+1,vector<int>(n+1,-1));

        int ans = solve(0,dp,pal,s);
        return ans;
    }
};