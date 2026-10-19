class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        auto it = upper_bound(nums.begin(),nums.end(),target);
        auto it1 = lower_bound(nums.begin(),nums.end(),target);
        int j = it-nums.begin();
        int i = it1-nums.begin();
        for(int x=i; x<j; x++){
            ans.push_back(x);
        }
        return ans;
        
    }
};