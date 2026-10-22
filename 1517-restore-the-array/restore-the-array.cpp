class Solution {
public:
    int MOD = 1e9+7;
    int solve(int i, vector<int>&dp , string &s, int k){
        int n = s.size();
        if(i==n)return 1;
        if(dp[i]!=-1)return dp[i];
        long long ans =0;
        long long num=0;
        for(int j=i; j<n; j++){
            int d = s[j]-'0';
            if(s[i]=='0') break;
            num = num*10+d;
            if(num>k) break;
            ans+=solve(j+1,dp,s,k);
        }
        return dp[i] = ans%MOD;
    }
    int numberOfArrays(string s, int k) {
        int n =s.size();
        vector<int>dp(n+1,-1);
        long long ans = solve(0,dp,s,k);
        return ans;
    }
};