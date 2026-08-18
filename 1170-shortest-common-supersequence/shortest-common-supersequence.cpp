class Solution {
public:
    string str(int i, int j,vector<vector<int>>&dp,string &str1,string &str2){
        string s;
        while(i<str1.size() && j<str2.size()){

            if(str1[i]==str2[j]){
                s.push_back(str1[i]);
                i++;
                j++;
            }
             else{
           //     int left = solve(i+1,j,dp,str1,str2);
            //    int right = solve(i,j+1,dp,str1,str2);
                if(dp[i+1][j]<dp[i][j+1]){
                    s.push_back(str1[i]);
                    i++;
                }else{
                    s.push_back(str2[j]);
                    j++;
                }
            }
        }
        if(i==str1.size()){
            while(j<str2.size()){
                s.push_back(str2[j]);
                j++;
            }
        }
        if(j==str2.size()){
            while(i<str1.size()){
                s.push_back(str1[i]);
                i++;
            }
        }
        return s;
    }
   // int solve(int i, int j,vector<vector<int>>&dp,string &str1, string &str2){
    //    if(i==str1.size()) return str2.size()-j;
    //   if(j==str2.size()) return str1.size()-i;
    //    if(dp[i][j]!=-1) return dp[i][j];

    //    if(str1[i]==str2[j]) return dp[i][j] = 1+solve(i+1,j+1,dp,str1,str2);
    //    return dp[i][j] = min(1+solve(i+1,j,dp,str1,str2),1+solve(i,j+1,dp,str1,str2));
   // }
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
     //   int scs_len = solve(0,0,dp,str1,str2);

     for(int j=0; j<=n; j++){
        dp[m][j] = n-j;
     }
     for(int i=0; i<=m; i++){
        dp[i][n] = m-i;
     }
       for(int i=m-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            if(str1[i]==str2[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }else{
                dp[i][j] = min(1+dp[i+1][j],1+dp[i][j+1]);
            }
        }
       }
        string scs = str(0,0,dp,str1,str2);
        return scs;
    }
};