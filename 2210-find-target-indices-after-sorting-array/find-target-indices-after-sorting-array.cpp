class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        auto it = upper_bound(nums.begin(),nums.end(),target);
        int j = it-nums.begin();
        for(int i=0; i<j; i++){
            if(nums[i]==target){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};