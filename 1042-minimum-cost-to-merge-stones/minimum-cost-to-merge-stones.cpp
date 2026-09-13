class Solution {
public:

    int solve(int i, int j, int p,
              vector<vector<vector<int>>>& dp,
              vector<int>& stones,
              vector<int>& prefix,
              int k) {
        if (i == j) {
            if (p == 1)
                return 0;
            return 1e9;
        }

        if (dp[i][j][p] != -1)
            return dp[i][j][p];

        int ans = 1e9;
        if (p > 1) {

            for (int m = i; m < j; m += k - 1) {

                int left = solve(
                    i, m, 1,
                    dp, stones, prefix, k
                );

                int right = solve(
                    m + 1, j, p - 1,
                    dp, stones, prefix, k
                );

                ans = min(ans, left + right);
            }
        }

        else {
            if ((j - i) % (k - 1) == 0) {

                int totalSum;

                if (i == 0)
                    totalSum = prefix[j];
                else
                    totalSum = prefix[j] - prefix[i - 1];

                ans = solve(
                    i, j, k,
                    dp, stones, prefix, k
                ) + totalSum;
            }
        }

        return dp[i][j][p] = ans;
    }

    int mergeStones(vector<int>& stones, int k) {

        int n = stones.size();
        if ((n - 1) % (k - 1) != 0)
            return -1;
        vector<int> prefix(n, 0);
        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(
                n,
                vector<int>(k + 1, -1)
            )
        );

        return solve(
            0,
            n - 1,
            1,
            dp,
            stones,
            prefix,
            k
        );
    }
};