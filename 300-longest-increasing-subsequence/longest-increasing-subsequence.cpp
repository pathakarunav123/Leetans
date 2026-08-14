class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>tail;
        for(int i=0;i<nums.size();i++){
            auto it = lower_bound(tail.begin(),tail.end(),nums[i]);
            int idx = it-tail.begin();
            if(it==tail.end()){
                tail.push_back(nums[i]);
            }else{
                tail[idx] = nums[i];
            }
        }
        return tail.size();
    }
};