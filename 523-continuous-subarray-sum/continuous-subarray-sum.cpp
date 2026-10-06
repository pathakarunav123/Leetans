class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefix(n + 1);
        prefix[0] = 0;

        for(int i = 1; i < prefix.size(); i++) {
            prefix[i] += prefix[i - 1] + nums[i - 1];
        }

        unordered_map<int, int> mp;
        mp[0] = 0;

        for(int i = 0; i < prefix.size(); i++) {
            int j = prefix[i] % k;

            if(mp.find(j) != mp.end()) {
                if(i - mp[j] >= 2)
                    return true;
            }
            else {
                mp[j] = i;
            }
        }

        return false;
    }
};