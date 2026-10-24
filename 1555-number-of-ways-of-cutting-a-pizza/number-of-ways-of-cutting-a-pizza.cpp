class Solution {
public:
    int MOD = 1e9+7;
    bool hasApple(int x, int y,int r1,int r2,vector<string>&pizza){
        bool ans = false;
        for(int i=x; i<=r1; i++){
            for(int j=y; j<=r2;j++){
                if(pizza[i][j]=='A'){
                    ans=true;
                }
            }
        }
        return ans;
    }
    int solve(int r, int c, int pieces, vector<vector<vector<int>>>&dp,vector<string>&pizza){
        int m = pizza.size();
        int n = pizza[0].size();
        if(pieces==1){
            if(hasApple(r,c,m-1,n-1,pizza)){
                return 1;
            }
            return 0;
        }
        if(dp[r][c][pieces]!=-1)return dp[r][c][pieces];
        int ways=0;
        for(int cut =r; cut<m-1; cut++){
            if(hasApple(r,c,cut,n-1,pizza)){
            ways = (ways +solve(cut+1,c,pieces-1,dp,pizza))%MOD;
            }
        }
        for(int cut=c; cut<n-1; cut++){
            if(hasApple(r,c,m-1,cut,pizza)){
            ways= (ways+solve(r,cut+1,pieces-1,dp,pizza))%MOD;
            }
        }
        return dp[r][c][pieces]=ways%MOD;
    }
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza[0].size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        long long ans = solve(0,0,k,dp,pizza);
        return ans;
    }
};