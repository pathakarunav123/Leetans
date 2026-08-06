class Solution {
public:
const int MOD = 1e9+7;
int solve(int i,int m, int currProfit,int minProfit,vector<vector<vector<int>>>&dp,vector<int>&group,vector<int>&profit){
    if(i>=group.size()){
        return (currProfit>=minProfit);
    }

  
    if(dp[i][m][currProfit]!=-1){
        return dp[i][m][currProfit];
    }
    int take = 0;
    if(group[i]<=m){
    take = solve(i+1,m-group[i],min(currProfit+profit[i],minProfit),minProfit,dp,group,profit);
    }
    int not_take = solve(i+1,m,currProfit,minProfit,dp,group,profit);
    int ans = (take+not_take)%MOD;
    return dp[i][m][currProfit] = ans;
}
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int totalProfit = 0;
        for(int i=0; i<profit.size(); i++){
            totalProfit+=profit[i];
        }
        if(totalProfit<minProfit){
            return 0;
        }
        int g = group.size();
        vector<vector<vector<int>>>dp(g+1,vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));
        int ans = solve(0,n,0,minProfit,dp,group,profit);
        return ans;    
    }
};