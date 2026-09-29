class Solution {
public:
    bool solve(int i,int j, int len, vector<vector<vector<int>>>&dp,unordered_map<char,int>&mp,string &s1, string &s2){
        if(len==1){
            return (s1[i]==s2[j]);
        }
        if(dp[i][j][len]!=-1) return dp[i][j][len];
        unordered_map<char,int>::iterator it=mp.begin();
        while(it!=mp.end()){
            if(it->second!=0){
                return false;
            }
            it++;
        }
        for(int k=1; k<len; k++){
            if(solve(i,j,k,dp,mp,s1,s2) && solve(i+k,j+k,len-k,dp,mp,s1,s2)){
                return dp[i][j][len]=1;
            }
            if(solve(i,j+(len-k),k,dp,mp,s1,s2) && solve(i+k,j,len-k,dp,mp,s1,s2)){
                return dp[i][j][len]=1;
            }
        }
        return dp[i][j][len]=0;

    }
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        unordered_map<char,int>mp;
        for(int i=0; i<m; i++){
            mp[s1[i]]++;
            mp[s2[i]]--;
        }
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        bool ans = solve(0,0,n,dp,mp,s1,s2);
        return ans;
    }
};