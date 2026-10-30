class Solution {
public:
    int getCost(int i, int j,vector<int>&houses){
        int mid = i+(j-i)/2;
        int mailbox = houses[mid];
        int sum=0;
        for(int x=i; x<=j; x++){
            sum+=abs(mailbox-houses[x]);
        }
        return sum;
    }
    int solve(int i, int j, vector<vector<int>>&dp, vector<int>&houses){
        if(i==houses.size()){
            if(j==0)return 0;
            return 1e9;
        }
            if(j==0) return 1e9;
            if(houses.size()-i < j) return 1e9;
            if(dp[i][j]!=-1)return dp[i][j];
            int ans =1e9;
            for(int x=i; x<=houses.size()-j; x++){
                ans = min(ans,getCost(i,x,houses)+solve(x+1,j-1,dp,houses));
            }
            return dp[i][j]=ans;
    }
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(),houses.end());
        int n = houses.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        int ans = solve(0,k,dp,houses);
        return ans;
    }
};