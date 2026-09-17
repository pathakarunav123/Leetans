class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
       vector<pair<int,int>> players;
       for(int i=0; i<n; i++){
        players.push_back({ages[i],scores[i]});
       }
       sort(players.begin(),players.end(), [](auto &a , auto &b){
        if(a.first==b.first){
            return a.second < b.second;
        }
        return a.first < b.first;
       });

       vector<int>dp(n,0);
      
       for(int i=0; i<n; i++){
        dp[i]=players[i].second;
        for(int j=0; j<i; j++){
            if(players[i].second>=players[j].second){
                dp[i]=max(dp[i],dp[j]+players[i].second);
            }
        }
       }
      int ans = -1e9;
      for(int i=0; i<n; i++){
        ans = max(ans,dp[i]);
      }
      return ans;
        
    }
};