class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&dp, string &s, string&p){
        if(i==s.size() && j==p.size()) return 1;
        if(i<s.size() && j==p.size()) return 0;
        if(i==s.size() && j<p.size()){
            for(int k =j; k<p.size(); k++){
                if(p[k]!='*'){
                    return 0;
                }
            }
               return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?'){
            if(solve(i+1,j+1,dp,s,p)){
                return dp[i][j]= 1;
            }        
        }
        if(p[j]=='*'){
            if(solve(i,j+1,dp,s,p)){
                return dp[i][j]=1;
            }
            if(solve(i+1,j,dp,s,p)){
                return dp[i][j]=1;
            }
        }
        return dp[i][j]=0;
    }
    
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+1,(vector<int>(m+1,-1)));
        bool ans = solve(0,0,dp,s,p);
        return ans;
    }
};