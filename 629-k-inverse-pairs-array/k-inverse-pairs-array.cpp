class Solution {
public:
    int MOD = 1e9 + 7;

    int kInversePairs(int n, int k) {
        long long maxPairs = 1LL * n * (n - 1) / 2;

        if (k > maxPairs) return 0;

        vector<vector<int>> dp(
            n + 1, vector<int>(k + 1, 0)
        );

        // Base case
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            // Exactly 0 inverse pairs: sorted permutation
            dp[i][0] = 1;

            // Prefix sum of the previous DP row
            vector<int> prefix(k + 1, 0);
            prefix[0] = dp[i - 1][0];

            for (int j = 1; j <= k; j++) {
                prefix[j] =
                    (prefix[j - 1] + dp[i - 1][j]) % MOD;
            }

            // Calculate current DP row using range sums
            for (int j = 1; j <= k; j++) {
                int L = max(0, j - i + 1);
                int R = j;

                int leftSum = (L > 0) ? prefix[L - 1] : 0;

                dp[i][j] =
                    (prefix[R] - leftSum + MOD) % MOD;
            }
        }

        return dp[n][k];
    }
};