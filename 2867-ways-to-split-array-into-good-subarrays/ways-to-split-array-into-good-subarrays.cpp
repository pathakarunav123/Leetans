class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int i, vector<int>& dp, vector<int>& nums) {
        if(dp[i] != -1)
            return dp[i];

        int ans = 0;
        bool found = false;

        for(int k = i + 1; k < nums.size(); k++) {
            if(nums[k] == 1) {
                found = true;

                ans = (long long)(k - i) * solve(k, dp, nums) % mod;
                break;
            }
        }

        // No next 1 -> this is the last 1
        if(!found)
            ans = 1;

        return dp[i] = ans;
    }

    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        int firstOne = -1;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                firstOne = i;
                break;
            }
        }

        if(firstOne == -1)
            return 0;

        return solve(firstOne, dp, nums);
    }
};