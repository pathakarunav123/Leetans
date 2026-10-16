
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();

        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], cost[i]};
        }

        sort(arr.begin(), arr.end());

        vector<long long> prefixCost(n + 1, 0);
        vector<long long> prefixWeighted(n + 1, 0);
        vector<int> sortedNums(n);

        for (int i = 0; i < n; i++) {
            sortedNums[i] = arr[i].first;

            prefixCost[i + 1] =
                prefixCost[i] + arr[i].second;

            prefixWeighted[i + 1] =
                prefixWeighted[i] +
                1LL * arr[i].first * arr[i].second;
        }

        long long ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            long long x = nums[i];

            int k = upper_bound(
                sortedNums.begin(),
                sortedNums.end(),
                x
            ) - sortedNums.begin();

            long long leftCost = prefixCost[k];
            long long leftWeighted = prefixWeighted[k];

            long long rightCost =
                prefixCost[n] - prefixCost[k];

            long long rightWeighted =
                prefixWeighted[n] - prefixWeighted[k];

            long long left =
                x * leftCost - leftWeighted;

            long long right =
                rightWeighted - x * rightCost;

            ans = min(ans, left + right);
        }

        return ans;
    }
};
