class Solution {
public:
    int jump(vector<int>& nums) {
        int jump =0;
        int currJump =0;
        int farJump=0;
        for(int i=0; i<nums.size()-1; i++){
            farJump = max(farJump,i+nums[i]);
            if(i==currJump){
                jump++;
                currJump=farJump;
            }
        }
        return jump;
        
    }
};