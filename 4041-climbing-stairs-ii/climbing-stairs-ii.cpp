class Solution {
public:
    int solve(int i, vector<int>& dp, vector<int>& cost, int n) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        int ans = cost[i] + 1 + solve(i + 1, dp, cost, n);
        if (i + 1 < n) {
            ans = min(ans, cost[i + 1] + 4 +
                       solve(i + 2, dp, cost, n));
        }

        if (i + 2 < n) {
            ans = min(ans, cost[i + 2] + 9 +
                       solve(i + 3, dp, cost, n));
        }

        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n, -1);
        return solve(0, dp, costs, n);
    }
};