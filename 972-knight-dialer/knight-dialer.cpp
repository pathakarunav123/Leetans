class Solution {
public:
    int MOD=1e9+7;
    int knightDialer(int n) {
        vector<vector<int>>prev={{4,6},{8,6},{7,9},{8,4},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}};
        vector<long long>dp(10,1);
        vector<long long>newDp(10,0);

        for(int len=2; len<=n; len++){
            for(int i=0; i<10; i++){
                newDp[i]=0;
                for(int j=0; j<prev[i].size(); j++){
                    int p = prev[i][j];
                    newDp[i]=(newDp[i]+dp[p])%MOD;
                }
            }
             dp=newDp;
        }  
        long long ans =0;
        for(int i=0; i<dp.size(); i++){
            ans = (ans + dp[i])%MOD;
        } 
        return ans;     
    }
};