class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int sum=0;
            int bre=nums[i];
            while(bre!=0){
                int digit = bre%10;
                sum+=digit;
                bre/=10;
            }
            if(sum==i){
                return i;
            }
            }
        
        return -1;
    }
};