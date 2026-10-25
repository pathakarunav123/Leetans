class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    // 2D prefix sum: O(1) mein rectangle ke apples count karo
    bool hasApple(int r1, int c1, int r2, int c2,
                  vector<vector<int>>& prefix) {
        int count = prefix[r2 + 1][c2 + 1]
                  - prefix[r1][c2 + 1]
                  - prefix[r2 + 1][c1]
                  + prefix[r1][c1];

        return count > 0;
    }

    int solve(int r, int c, int pieces,
              vector<vector<vector<int>>>& dp,
              vector<vector<int>>& prefix,
              int m, int n) {
        if (pieces == 1) {
            return hasApple(r, c, m - 1, n - 1, prefix) ? 1 : 0;
        }

        int& ans = dp[r][c][pieces];
        if (ans != -1) {
            return ans;
        }

        long long ways = 0;

        // Horizontal cuts
        for (int cut = r; cut < m - 1; cut++) {
            // Upar wala piece: rows r..cut, columns c..n-1
            if (hasApple(r, c, cut, n - 1, prefix)) {
                ways += solve(cut + 1, c, pieces - 1,
                              dp, prefix, m, n);
                ways %= MOD;
            }
        }

        // Vertical cuts
        for (int cut = c; cut < n - 1; cut++) {
            // Left wala piece: rows r..m-1, columns c..cut
            if (hasApple(r, c, m - 1, cut, prefix)) {
                ways += solve(r, cut + 1, pieces - 1,
                              dp, prefix, m, n);
                ways %= MOD;
            }
        }

        return ans = static_cast<int>(ways);
    }

    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza[0].size();

        // prefix[i][j] = pizza ke (0,0) se (i-1,j-1)
        // tak ke rectangle mein total apples
        vector<vector<int>> prefix(
            m + 1, vector<int>(n + 1, 0)
        );

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] =
                    prefix[i - 1][j]
                    + prefix[i][j - 1]
                    - prefix[i - 1][j - 1]
                    + (pizza[i - 1][j - 1] == 'A');
            }
        }

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(
                n, vector<int>(k + 1, -1)
            )
        );

        return solve(0, 0, k, dp, prefix, m, n);
    }
};