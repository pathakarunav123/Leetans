class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int t = 0;
        for(int i=0; i<nums.size(); i++){
            t+=nums[i];
        }
        int target = t - x;
        int l = 0;
        int sum = 0;
        int maxLen = -1;

        for(int r=0; r<nums.size(); r++){
            sum+=nums[r];
            while(sum>target && l<=r){
                 sum-=nums[l++];
            }
             if(sum==target){
                maxLen = max(maxLen,r-l+1);
                }
        } 
       return maxLen==-1?-1:(int)nums.size()-maxLen;
    
    }
};