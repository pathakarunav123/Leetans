
class Solution {
public:
    vector<vector<long long>> memo;
    vector<int> nums;
    long long solve(int j, int i) {
        if (memo[j][i] != -1)
            return memo[j][i];
        long long diff = (long long)nums[i] - nums[j];
        long long count = 0;
        for (int k = 0; k < j; k++) {
            long long prevDiff =
                (long long)nums[j] - nums[k];

            if (prevDiff == diff) {
                // New subsequence of length 3
                // + extend all existing subsequences
                count += 1 + solve(k, j);
            }
        }

        return memo[j][i] = count;
    }

    int numberOfArithmeticSlices(vector<int>& arr) {
        nums = arr;
        int n = nums.size();
        memo.assign(n, vector<long long>(n, -1));
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                ans += solve(j, i);
            }
        }

        return (int)ans;
    }
};
