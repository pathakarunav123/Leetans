class Solution {
public:
    int solve(int i, vector<int>&dp, vector<int>&nums, int k){
        if(i==nums.size()) return 0;
        if(dp[i]!=-1)return dp[i];
        int ans = INT_MAX;
        int trimmed=0;
        unordered_map<int,int>mp;
        for(int j=i; j<nums.size(); j++){
            mp[nums[j]]++;
            if(mp[nums[j]]==2){
                trimmed+=mp[nums[j]];
            }else if(mp[nums[j]]>2){
                trimmed++;
            }

           ans = min(ans,k+trimmed+solve(j+1,dp,nums,k));
        }
        return dp[i]=ans;
    }
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        int ans = solve(0,dp,nums,k);
        return ans;
    }
}; 