class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& dp,
              vector<int>& nums) {

        if(i == nums.size() - 1)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        int notTake = solve(i + 1, j, dp, nums);
        int take = 0;
        if(j == 1 && nums[i + 1] > nums[i]) {
            take = 1 + solve(i + 1, 0, dp, nums);
        }

       
        if(j == 0 && nums[i + 1] < nums[i]) {
            take = 1 + solve(i + 1, 1, dp, nums);
        }

        return dp[i][j] = max(take, notTake);
    }

    int wiggleMaxLength(vector<int>& nums) {

        int n = nums.size();

        if(n <= 1)
            return n;

        vector<vector<int>> dp(n, vector<int>(2, -1));
        int up = solve(0, 1, dp, nums);
        int down = solve(0, 0, dp, nums);

        return 1 + max(up, down);
    }
};