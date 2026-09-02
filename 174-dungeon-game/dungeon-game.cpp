class Solution {
public:
    int solve(int i, int j,vector<vector<int>>&dp,vector<vector<int>>&dungeon){
        int m = dungeon.size();
        int n= dungeon[0].size();
        if(i==m-1 && j==n-1){
            return max(1,1-dungeon[i][j]);
        }
        if(i==m || j==n) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int right = solve(i,j+1,dp,dungeon);
        int down = solve(i+1,j,dp,dungeon);
        int next = min(right,down);
        return dp[i][j] = max(1,next-dungeon[i][j]);

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans = solve(0,0,dp,dungeon);
        return ans;
    }
};