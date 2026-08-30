class Solution {
public:
    int solve(map<vector<int>,int>&dp, vector<int>&price,vector<vector<int>>&special,vector<int>&needs){
        int ans = 1e9;
        bool done =true;
        for(int x=0; x<needs.size(); x++){
            if(needs[x]!=0){
                done=false;
                break;
            }
        }
        if(done) return 0;
        if(dp.count(needs)){
            return dp[needs];
        }
        int normalCost =0;
        for(int i=0; i<price.size(); i++){
            normalCost+=needs[i]*price[i];
        }
        ans=normalCost;
        for(int j=0; j<special.size(); j++){
            vector<int>nn=needs;
            bool valid = true;
            for(int i=0; i<price.size(); i++){
                if(special[j][i]>needs[i]){
                    valid = false;
                    break;
                }
                nn[i]-=special[j][i];
            }
            if(valid){
                ans = min(ans,special[j][price.size()]+solve(dp,price,special,nn));
            }
        }
        return dp[needs] = ans;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = needs.size();
        map<vector<int>,int>dp;
        int ans = solve(dp,price,special,needs);
        return ans;
    }
};