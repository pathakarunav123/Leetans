
class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int i, int a, int b, int k,
              string &s,
              vector<vector<vector<vector<int>>>> &dp) {

        // All 5 characters selected
        if (k == 5)
            return 1;

        // String exhausted
        if (i == s.size())
            return 0;

        // Memoization
        int &ans = dp[i][a + 1][b + 1][k];

        if (ans != -1)
            return ans;

        // Option 1: Skip current character
        long long ways = solve(i + 1, a, b, k, s, dp);

        int d = s[i] - '0';

        // Option 2: Take current character
        if (k == 0) {
            ways += solve(i + 1, d, b, 1, s, dp);
        }
        else if (k == 1) {
            ways += solve(i + 1, a, d, 2, s, dp);
        }
        else if (k == 2) {
            ways += solve(i + 1, a, b, 3, s, dp);
        }
        else if (k == 3 && d == b) {
            ways += solve(i + 1, a, b, 4, s, dp);
        }
        else if (k == 4 && d == a) {
            ways += solve(i + 1, a, b, 5, s, dp);
        }

        return ans = ways % MOD;
    }

    int countPalindromes(string s) {
        int n = s.size();

        vector<vector<vector<vector<int>>>> dp(
            n,
            vector<vector<vector<int>>>(
                11,
                vector<vector<int>>(
                    11,
                    vector<int>(6, -1)
                )
            )
        );

        return solve(0, -1, -1, 0, s, dp);
    }
};
