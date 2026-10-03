class Solution {
public:
    int solve(int i, int d,vector<vector<int>>&dp,vector<int>&rods){
        if(i==rods.size()){
            if(d==0){
                return 0;
            }
            return -1e9;
        }
        if(dp[i][d]!=-1)return dp[i][d];
        //ignore
        int ignore =solve(i+1,d,dp,rods);
        //taller side
            int taller= solve(i+1,d+rods[i],dp,rods);
        //shorter side
        int new_shorter = min(rods[i],d);
        int new_diff = abs(d-rods[i]);
        int shorter = new_shorter+solve(i+1,new_diff,dp,rods);
        return dp[i][d]=max({ignore,taller,shorter});
       
    }
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int totalSum=0;
        for(int i=0;i<rods.size(); i++){
            totalSum+=rods[i];
        }
        vector<vector<int>>dp(n+1,vector<int>(totalSum+1,-1));
        int ans = solve(0,0,dp,rods);
        return ans;
    }
};