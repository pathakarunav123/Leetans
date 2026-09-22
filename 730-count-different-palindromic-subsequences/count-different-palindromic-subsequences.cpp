class Solution {
public:
    int MOD = 1e9+7;
    long long solve(int l, int r, vector<vector<long long>>&dp,string &s,vector<vector<int>>&pos){
       if(l==r) return 1;
       if(l>r) return 0;
       if(dp[l][r]!=-1) return dp[l][r];
       if(s[l]!=s[r]){
        return dp[l][r]=((solve(l+1,r,dp,s,pos)+solve(l,r-1,dp,s,pos)-solve(l+1,r-1,dp,s,pos)+MOD)%MOD);
       }else{
        int c = s[l] - 'a';
        int p = *upper_bound(pos[c].begin(),pos[c].end(),l);
        auto it = lower_bound(pos[c].begin(),pos[c].end(),r);
        it--;
        int q = *it;
        if(p>q){
            return dp[l][r]=(2*solve(l+1,r-1,dp,s,pos)+2)%MOD;
        }else if(p==q){
            return dp[l][r]=(2*solve(l+1,r-1,dp,s,pos)+1)%MOD;
        }else{
            return dp[l][r]=(2*solve(l+1,r-1,dp,s,pos)-solve(p+1,q-1,dp,s,pos)+MOD)%MOD; 
        }
       }
       return dp[l][r];
    }
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));
        vector<vector<int>> pos(4);
        for(int i=0; i<n; i++){
         pos[s[i] - 'a'].push_back(i);
        }
        
        int ans = solve(0,n-1,dp,s,pos);
        return ans;
    }
};