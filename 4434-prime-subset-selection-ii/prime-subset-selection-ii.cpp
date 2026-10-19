
class Solution {
public:
    vector<int> primes;
    vector<vector<int>> dp;

    const int INF = 1e9;

    int solve(int i, int sum) {
        if (sum == 0) return 0;
        if (i == primes.size()) return INF;

        int &ans = dp[i][sum];
        if (ans != -1) return ans;

        // Skip current prime
        int notTake = solve(i + 1, sum);

        // Take current prime
        int take = INF;
        if (primes[i] <= sum) {
            int sub = solve(i + 1, sum - primes[i]);
            if (sub != INF) take = 1 + sub;
        }

        return ans = min(take, notTake);
    }

    vector<int> maxPrimeSubset(int n, int s) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false;
        if (n >= 1) isPrime[1] = false;

        for (int p = 2; p <= n / p; ++p) {
            if (isPrime[p]) {
                for (int j = p * p; j <= n; j += p)
                    isPrime[j] = false;
            }
        }

        primes.clear();
        for (int p = 2; p <= n && p <= s; ++p) {
            if (isPrime[p]) primes.push_back(p);
        }

        int m = primes.size();
        dp.assign(m + 1, vector<int>(s + 1, -1));

        int bestSum = 0;

        // Maximum achievable sum
        for (int sum = s; sum >= 1; --sum) {
            if (solve(0, sum) != INF) {
                bestSum = sum;
                break;
            }
        }

        if (bestSum == 0) return {};

        int bestCount = solve(0, bestSum);

        // Lexicographically smallest reconstruction
        vector<int> ans;
        int remainingSum = bestSum;
        int start = 0;
        int remainingCount = bestCount;

        while (remainingCount > 0) {
            for (int i = start; i < m; ++i) {
                int p = primes[i];

                if (p > remainingSum) break;

                int sub = solve(i + 1, remainingSum - p);

                if (sub == remainingCount - 1) {
                    ans.push_back(p);
                    remainingSum -= p;
                    remainingCount--;
                    start = i + 1;
                    break;
                }
            }
        }

        return ans;
    }
};
