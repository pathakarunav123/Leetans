class Solution {
public:
    int path(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();

        if (i == m - 1) {
            return grid[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int currValue = grid[i][j];
        int minValue = INT_MAX;

        for (int nextCol = 0; nextCol < n; nextCol++) {
            int moveVal = moveCost[currValue][nextCol];
            int gridVal = grid[i][j] + path(i + 1, nextCol, grid, moveCost, dp); 
            minValue = min(minValue, moveVal + gridVal);
        }

        return dp[i][j] = minValue;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        int mini = INT_MAX;

        for (int col = 0; col < n; col++) {
            int ans = path(0, col, grid, moveCost, dp);
            mini = min(mini, ans);
        }

        return mini;
    }
};
