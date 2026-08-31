class Solution {
public:
    int solve(int i, vector<int>&dp, vector<int>&nums){
        if(i>=nums.size()-1){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int pick = 1e9;
        int mini = 1e9;
        for(int j=1; j<=nums[i]; j++){
            int jump = j+i;
            pick = solve(jump,dp,nums);
            if(pick!=1e9){
                mini=min(mini,1+pick);
            }
        }
        return dp[i]=mini;
    }
    int jump(vector<int>& nums) {
       // int jump =0;
       // int currJump =0;
       // int farJump=0;
       // for(int i=0; i<nums.size()-1; i++){
       //     farJump = max(farJump,i+nums[i]);
       //     if(i==currJump){
       //         jump++;
       //         currJump=farJump;
       //     }
       // }
       // return jump;
       int n = nums.size();
       vector<int>dp(n+1,-1);
       int ans = solve(0,dp,nums);
       return ans;
    }
};