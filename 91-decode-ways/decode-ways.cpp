class Solution {
public:
    int solve(int i,vector<int>&dp,string &s){
        if(i==s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        int dig1_num = s[i]-'0';
        int pick =0;
        if(1<=dig1_num && dig1_num<=9){
            pick = solve(i+1,dp,s);
        }
         int not_pick =0;
        if(i+1<s.size()){
            int dig2_num =(s[i]-'0')*10+(s[i+1]-'0');
            if(10<=dig2_num && dig2_num<=26){
            not_pick = solve(i+2,dp,s);
            }
        }
        return dp[i] = pick + not_pick;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int>dp(n+1,-1);
        int ans = solve(0,dp,s);
        return ans;
        
    }
};