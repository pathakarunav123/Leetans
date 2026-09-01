class Solution {
public:
    int candy(vector<int>& ratings) {
        int n  = ratings.size();
        vector<int>give(ratings.size(),1);
        for(int i=1; i<give.size(); i++){
            if(ratings[i]>ratings[i-1]){
                give[i]= 1+give[i-1];
            }
        }
        for(int j=n-2; j>=0; j--){
            if(ratings[j]>ratings[j+1]){
                give[j] = max(give[j],1+give[j+1]);
            }
        }
        int ans=0;
        for(int i=0; i<give.size(); i++){
            ans+=give[i];
        }
        return ans;
        
    }
};