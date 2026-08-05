class Solution {
public:
     int solve(int i,int m,int n,vector<vector<vector<int>>>&dp,vector<string>&strs){
        int l = strs.size();
        if(i>=l) return 0;
        string target = strs[i];
        int zeroCount = count(target.begin(),target.end(),'0');
        int oneCount = count(target.begin(),target.end(),'1');
        if(dp[i][m][n]!=-1){
            return dp[i][m][n];
        }
        int take = 0;
        if(zeroCount<=m && oneCount<=n){
            take = 1+solve(i+1,m-zeroCount,n-oneCount,dp,strs);
        }
        int not_take = solve(i+1,m,n,dp,strs);
        return dp[i][m][n] = max(take,not_take);
     }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l =strs.size();
        vector<vector<vector<int>>>dp(l+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        int ans = solve(0,m,n,dp,strs);
        return ans;
    }
};