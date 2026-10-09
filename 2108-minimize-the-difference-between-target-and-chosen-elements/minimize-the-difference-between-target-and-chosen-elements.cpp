class Solution {
public:
    int solve(int i, int sum, vector<vector<int>>&dp, vector<vector<int>>&mat,int target){
        if(i>=mat.size()){
            return abs(target-sum);
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        int maxi = 1e9;
        for(int j =0; j<mat[0].size(); j++){
                maxi = min(maxi,solve(i+1,sum+mat[i][j],dp,mat,target));
        }
        return dp[i][sum]=maxi;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m =mat.size();
        int n = mat[0].size();
        int totalSum=0;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size();j++){
                totalSum+=mat[i][j];
            }
        }
        vector<vector<int>>dp(m+1,vector<int>(totalSum,-1));
        int ans = solve(0,0,dp,mat,target);
       // int res = target-ans;
        return ans;
    }
};