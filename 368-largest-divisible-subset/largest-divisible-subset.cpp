class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>track(n,-1);
        int last_idx = 0;
        for(int i=0;i<n;i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0){
                    if(dp[j]+1>dp[i]){
                       dp[i]=dp[j]+1;
                       track[i] = j;
                    }
                }
            }
        }
        for(int i=0; i<dp.size(); i++){
            if(dp[i]>dp[last_idx]){
                last_idx = i;
            }
        }
        vector<int>ans;
        int idx = last_idx;
        while(idx!=-1){
            ans.push_back(nums[idx]);
            idx = track[idx];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};