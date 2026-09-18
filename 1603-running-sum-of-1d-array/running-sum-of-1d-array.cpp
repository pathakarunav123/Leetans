class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>prefixSum(nums.size(),0);
        prefixSum[0]=nums[0];
        for(int i=1; i<prefixSum.size(); i++){
            prefixSum[i]=nums[i]+prefixSum[i-1];
        }
        return prefixSum;
    }
};