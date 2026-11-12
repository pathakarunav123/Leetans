class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int maxi = 0;
            int count = 0;

            while (num > 0) {
                int digit = num % 10;
                maxi = max(maxi, digit);
                count++;
                num /= 10;
            }

            int encrypted = 0;

            while (count > 0) {
                encrypted = encrypted * 10 + maxi;
                count--;
            }

            ans += encrypted;
        }

        return ans;
    }
};