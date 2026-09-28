class Solution {
public:
    int solve(int i, int j, int k, vector<vector<vector<int>>>&dp, vector<int>&houses,vector<vector<int>>&cost, int m, int n, int target){
        //base case
        if(i==m){
            if(k==target){
                return 0;
            }
            return 1e9;
        }
        if(k>target){
            return 1e9;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int ans = 1e9;
        if(houses[i]!=0){
            if(houses[i]==j){
                ans = solve(i+1,j,k,dp,houses,cost,m,n,target);
            }else{
                ans = solve(i+1,houses[i],k+1,dp,houses,cost,m,n,target);
            }
        }else{
            for(int col=1; col<=n; col++){
                if(j==col){
                    ans = min(ans,solve(i+1,j,k,dp,houses,cost,m,n,target)+cost[i][col-1]);
                }else{
                    ans=min(ans,solve(i+1,col,k+1,dp,houses,cost,m,n,target)+cost[i][col-1]);
                }
            }
        }
        return dp[i][j][k]=ans;

    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(target+1,-1)));
        int ans = solve(0,0,0,dp,houses,cost,m,n,target);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};