class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        set<pair<int,int>>s1 , s2;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(img1[i][j] == 1) s1.insert({i,j});
                if(img2[i][j] == 1) s2.insert({i,j});
            }
        }

        int ans = 0;
        map<pair<int,int> , int>cnt;
        for(auto &[r1 , c1] : s1){
            for(auto &[r2, c2] : s2){
                cnt[{r1-r2 , c1-c2}]++;
                ans = max(ans , cnt[{r1-r2 , c1-c2}]);
            }
        }
        return ans;
    }
};