class Solution {
public:
    int solve(int i, int j, int m, int n,vector<vector<int>>&dp,vector<vector<char>>&matrix){
        if(i==0 || j==0) return (matrix[i][j]=='1');
        if(matrix[i][j]=='0') return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int top = solve(i-1,j,m,n,dp,matrix);
        int left_dig = solve(i-1,j-1,m,n,dp,matrix);
        int left = solve(i,j-1,m,n,dp,matrix);
        int mini = 1+min({top,left_dig,left});
        return dp[i][j] = mini;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans = INT_MIN;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = max(ans,solve(i,j,m,n,dp,matrix));
            }
        }
        return ans*ans;
    }
};