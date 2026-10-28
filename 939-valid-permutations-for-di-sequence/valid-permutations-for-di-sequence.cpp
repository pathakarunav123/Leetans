class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    vector<vector<int>> memo;
    string s;

    int solve(int i, int rank) {
        // Base case
        if (i == 0) {
            return rank == 0 ? 1 : 0;
        }

        int& ans = memo[i][rank];

        if (ans != -1) {
            return ans;
        }

        long long ways = 0;

        if (s[i - 1] == 'I') {
            // Previous rank must be smaller
            for (int j = 0; j < rank; j++) {
                ways += solve(i - 1, j);
                ways %= MOD;
            }
        } else {
            // Previous rank must be >= current rank
            for (int j = rank; j < i; j++) {
                ways += solve(i - 1, j);
                ways %= MOD;
            }
        }

        return ans = static_cast<int>(ways);
    }

    int numPermsDISequence(string str) {
        s = str;
        int n = s.size();

        memo.assign(n + 1, vector<int>(n + 1, -1));

        long long ans = 0;

        for (int rank = 0; rank <= n; rank++) {
            ans += solve(n, rank);
            ans %= MOD;
        }

        return static_cast<int>(ans);
    }
};