class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
      //  vector<int>dp(n,1);
        sort(envelopes.begin(),envelopes.end(),[](vector<int>&a, vector<int>&b){
            if(a[0]==b[0]){
            return a[1]>b[1];
            }
            return a[0]<b[0];
        });

        vector<int>tail;
        for(int i=0; i<n;i++){
            auto it = lower_bound(tail.begin(),tail.end(),envelopes[i][1]);
            int idx = it-tail.begin();
            if(it==tail.end()){
                tail.push_back(envelopes[i][1]);
            }else{
                tail[idx]=envelopes[i][1];
            }
        }
        return tail.size();
    }
};