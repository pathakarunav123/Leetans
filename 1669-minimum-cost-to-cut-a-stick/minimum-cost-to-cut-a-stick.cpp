class Solution {
public:
    int solve(int i, int j,vector<vector<int>>&dp,vector<int>&cuts){
      if(j==i+1)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      int ans = 1e9;
      for(int k=i+1;k<j; k++){
        ans = min(ans,solve(i,k,dp,cuts)+solve(k,j,dp,cuts)+(cuts[j]-cuts[i]));
      }
      return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.insert(cuts.end(),n);
        sort(cuts.begin(),cuts.end());
         int m = cuts.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        int ans = solve(0, m-1, dp, cuts);
        return ans;        
    }
};