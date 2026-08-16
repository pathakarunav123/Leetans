class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n =obstacles.size();
        vector<int>dp(n,1);
        vector<int>tail;
        for(int i=0;i<n;i++){
            auto it = upper_bound(tail.begin(),tail.end(),obstacles[i]);
            int idx = it-tail.begin();
            if(it==tail.end()){
                tail.push_back(obstacles[i]);
            }else{
                tail[idx] = obstacles[i];
            }
            dp[i]=idx+1;
        }
        return dp;
        
    }
};