class Solution {
public:
    vector<string> solve(int i,vector<vector<string>>&dp,vector<bool>&vis,unordered_map<string,int>&mp,string &s){
        int n = s.size();
        if(i==n) return {""};
        if(vis[i]!=false) return dp[i];
        for(int j =i; j<s.size(); j++){
            string temp = s.substr(i,j-i+1);
            if(mp.find(temp)!=mp.end()){
                vector<string>child = solve(j+1,dp,vis,mp,s);
                for(int k=0; k<child.size(); k++){
                    if(child[k].empty()){
                        dp[i].push_back(temp);
                    }else{
                    string ans = temp + " " + child[k];
                    dp[i].push_back(ans);
                    }
                }
                
            }
        }
        vis[i]=true;
        return dp[i];
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<vector<string>>dp(n+1);
        vector<bool>vis(n+1,false);
        unordered_map<string,int>mp;
        for(int i=0; i<wordDict.size(); i++){
            mp[wordDict[i]]++;
        }
        vector<string>ans = solve(0,dp,vis,mp,s);
        return ans;
    }
};