class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=INT_MIN;
        int n = nums.size();
        for(int i=0; i<nums.size(); i++){
            maxi=max(maxi,nums[i]);
        }
        int ans =0;
        for(int i=0; i<nums.size(); i++){
            ans+=(maxi-nums[i]);
        }
        return ans;
    }
};