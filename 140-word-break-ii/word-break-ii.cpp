class Solution {
public:
    void solve(int i, int j,vector<string>&path,vector<string>&result,unordered_map<string,int>&mp,string s){
        if(i==s.size()){
            string sen;
           for(int i=0; i<path.size(); i++){
             sen+= path[i];
            if(i!=path.size()-1){
                 sen+= " ";
            }
           }
           result.push_back(sen);
           return;
        }
        if(j>=s.size())return;
        string temp = s.substr(i,j-i+1);
        if(mp.find(temp)!=mp.end()){
           path.push_back(temp);
            solve(j+1,j+1,path,result,mp,s);
            path.pop_back();
        }
                
                
           solve(i,j+1,path,result,mp,s);
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    unordered_map<string,int>mp;
    for(int i=0; i<wordDict.size(); i++){
        mp[wordDict[i]]=i;
    }
    vector<string>path;
    vector<string>result;
     solve(0,0,path,result,mp,s);
    return result;
    }
};