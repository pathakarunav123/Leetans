class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int>dp(n,1);
        for(int i=0; i<pairs.size();i++){
            for(int j=0; j<i; j++){
                if(pairs[i][0]>pairs[j][1]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        int maxi =0;
        for(int i=0; i<dp.size(); i++){
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};