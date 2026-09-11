class Solution {
public:
    int helper(int i, int j, vector<vector<int>>&cost, string &s){
        if(i==j){
            return 0;
        }
        if(i>j) return 0;
        if(cost[i][j]!=0) return cost[i][j];
        int pal = 0;
        int not_pal = 0;
        if(s[i]==s[j]){
            pal = helper(i+1,j-1,cost,s);
        }else{
            not_pal = 1+helper(i+1,j-1,cost,s);
        }
        return cost[i][j] = pal+not_pal;
    }
    int solve(int i, int k,vector<vector<int>>&dp,vector<vector<int>>&cost,string &s){
        if(k==0){
           if(i==s.size()){
            return 0;
           }else{
            return 1e9;
           }
        }
        if(dp[i][k]!=-1) return dp[i][k];
        int ans = 1e9;
        int cand =0;
        for(int j=i; j<s.size(); j++){
            int change = helper(i,j,cost,s);
             cand = change + solve(j+1,k-1,dp,cost,s);
             ans = min(ans,cand);
        }
        return dp[i][k]=ans;
    }
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        vector<vector<int>>cost(n+1,vector<int>(n+1,0));
        int ans = solve(0,k,dp,cost,s);
        return ans;
    }
};