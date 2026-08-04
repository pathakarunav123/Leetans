class Solution {
public:
    int solve(int i, int sum, vector<vector<int>>&dp,vector<int>&stones,int totalSum){
        int n = stones.size();
        if(i>=n) return sum;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int take =0;
        if(stones[i]+sum<=totalSum/2){
            take = solve(i+1,sum+stones[i],dp,stones,totalSum);
        }
        int not_take = solve(i+1,sum,dp,stones,totalSum);
        return dp[i][sum] = max(take,not_take);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        int totalSum=0;
        for(int i=0; i<stones.size(); i++){
            totalSum+=stones[i];
        }
        vector<vector<int>>dp(n+1,vector<int>(totalSum/2+1,-1));

        int best = solve(0,sum,dp,stones,totalSum);
        int ans = totalSum - (2*best);
        return ans;
    }
};