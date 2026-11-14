class Solution {
public:
    long long solve(int j, int i,vector<vector<long long>>&dp, vector<int>&nums){
        if(dp[j][i]!=-1) return dp[j][i];
        long long diff =  (long long)nums[i]-nums[j];
        long long count =0;
        for(int k=0; k<j; k++){
            long long prevdiff=(long long)nums[j]-nums[k];
            if(prevdiff==diff){
                count+=1+solve(k,j,dp,nums);
            }
        }
        return dp[j][i]=count;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));
        long long ans =0;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                ans+=solve(j,i,dp,nums);
            }
        }
        return (int)ans; 
    }
};