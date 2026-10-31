class Solution {
public:
    int getCost(int i, int j,vector<int>&houses,vector<int>&prefix){
        int n = houses.size();
        int m = i+(j-i)/2;
       int leftCost = (m-i)*houses[m]-(prefix[m]-prefix[i]);
       int rightCost =(prefix[j+1]-prefix[m+1])-(j-m)*houses[m];
       return (leftCost+rightCost);
    }
    int solve(int i, int j, vector<vector<int>>&dp, vector<int>&houses,vector<int>&prefix){
        if(i==houses.size()){
            if(j==0)return 0;
            return 1e9;
        }
            if(j==0) return 1e9;
            if(houses.size()-i < j) return 1e9;
            if(dp[i][j]!=-1)return dp[i][j];
            int ans =1e9;
            for(int x=i; x<=houses.size()-j; x++){
                ans = min(ans,getCost(i,x,houses,prefix)+solve(x+1,j-1,dp,houses,prefix));
            }
            return dp[i][j]=ans;
    }
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(),houses.end());
        int n = houses.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        vector<int>prefix(n+1);
        prefix[0]=0;
        for(int i=1; i<prefix.size(); i++){
            prefix[i]=prefix[i-1]+houses[i-1];
        }
        int ans = solve(0,k,dp,houses,prefix);
        return ans;
    }
};