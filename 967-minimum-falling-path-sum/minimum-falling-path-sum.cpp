class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

      
        for(int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

   
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int st = dp[i-1][j];
               int ld = INT_MAX;
               if(j>0){
                ld = dp[i-1][j-1];
               }
               int rd = INT_MAX;
               if(j<n-1){
                rd = dp[i-1][j+1];
               }
                dp[i][j] = matrix[i][j] + min({st, ld, rd});
            }
        }

        return *min_element(dp[m-1].begin(), dp[m-1].end());
    }
};