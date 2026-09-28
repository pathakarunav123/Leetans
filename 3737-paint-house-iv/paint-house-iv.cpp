class Solution {
public:
    long long solve(int i,int a, int b, vector<vector<vector<long long>>>&dp,int n, vector<vector<int>>&cost){
        if(i>n-1-i)return 0;
        if(dp[i][a][b]!=-1)return dp[i][a][b];
       long long ans = 1e18;
        for(int c=0; c<3; c++){
            for(int d=0; d<3; d++){
                if(c!=d && a!=c && b!=d){
                    ans = min(ans,cost[i][c]+cost[n-1-i][d]+solve(i+1,c,d,dp,n,cost));
                }
            }
        }
        return dp[i][a][b]=ans;
    }

    long long minCost(int n, vector<vector<int>>& cost) {
        int m = cost[0].size();
        vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(m+1,vector<long long>(m+1,-1)));
        long long ans =1e18;
        for(int a=0; a<3; a++){
            for(int b=0; b<3; b++){
                if(a!=b){
                    ans = min(ans,cost[0][a]+cost[n-1][b]+solve(1,a,b,dp,n,cost));
                }
            }
        }
        return ans;
    }
};