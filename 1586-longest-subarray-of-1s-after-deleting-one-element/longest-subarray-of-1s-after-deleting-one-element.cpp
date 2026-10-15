
class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int solve(int i, int k, vector<int>& nums) {
        if (i == n)
            return 0;

        if (memo[i][k] != -1)
            return memo[i][k];

        if (nums[i] == 1) {
            return memo[i][k] =
                1 + solve(i + 1, k, nums);
        }

        if (k == 0) {
            return memo[i][k] =
                solve(i + 1, 1, nums);
        }

        return memo[i][k] = 0;
    }

    int longestSubarray(vector<int>& nums) {
        n = nums.size();
        memo.assign(n, vector<int>(2, -1));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(i, 0, nums));
        }
        return min(ans, n - 1);
    }
};
