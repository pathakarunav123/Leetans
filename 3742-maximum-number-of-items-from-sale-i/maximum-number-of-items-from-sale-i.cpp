class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
         int n = items.size();

        vector<int> gain(n);

        // Calculate first-purchase benefit
        for (int i = 0; i < n; i++) {
            gain[i] = 1;

            for (int j = 0; j < n; j++) {
                if (i != j &&
                    items[j][0] % items[i][0] == 0) {
                    gain[i]++;
                }
            }
        }

        // Sort items by price descending
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int a, int b) {
            return items[a][1] > items[b][1];
        });

        const int NEG = -1e9;

        // dp[b]: maximum benefit using items
        // strictly more expensive than current group
        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        int ans = 0;
        int idx = 0;

        while (idx < n) {
            int p = items[order[idx]][1];

            // Current group must contain at least one item
            vector<int> cur(budget + 1, NEG);

            while (idx < n && items[order[idx]][1] == p) {
                int id = order[idx];
                int val = gain[id];

                // 0/1 selection of this item
                for (int b = budget; b >= p; b--) {

                    if (dp[b - p] != NEG) {
                        cur[b] = max(
                            cur[b],
                            dp[b - p] + val
                        );
                    }

                    if (cur[b - p] != NEG) {
                        cur[b] = max(
                            cur[b],
                            cur[b - p] + val
                        );
                    }
                }

                idx++;
            }

            // Current group establishes minimum selected price
            for (int b = 0; b <= budget; b++) {
                if (cur[b] == NEG) continue;
                ans = max(
                    ans,
                    cur[b] + (budget - b) / p
                );

                dp[b] = max(dp[b], cur[b]);
            }
        }

        return ans;
        
    }
};