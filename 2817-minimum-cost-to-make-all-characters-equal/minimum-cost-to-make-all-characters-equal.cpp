class Solution {
public:
    long long solve(int i, vector<long long>&dp, string &s){
        long long n = s.size();
        if(i==n) return 0;
        if(dp[i]!=-1)return dp[i];
        long long cost =0;
        if(s[i]!=s[i-1]){
            cost += min(1LL*i,n-i);
        }
         return dp[i] = cost+solve(i+1,dp,s);
    }
    long long minimumCost(string s) {
        long long n = s.size();
        vector<long long>dp(n+1,-1);
        long long ans= solve(1,dp,s);
        return ans;
    }
};