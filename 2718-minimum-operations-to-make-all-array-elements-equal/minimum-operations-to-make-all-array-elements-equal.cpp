class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n =nums.size();
        int m =queries.size();
        sort(nums.begin(),nums.end());
        vector<long long>prefix(n+1);
        prefix[0]=0;
        vector<long long>ans;
        for(int i=1; i<prefix.size(); i++){
            prefix[i] = prefix[i-1]+1LL*nums[i-1];
        }
        for(int i=0; i<m; i++){
            long long x = queries[i];
            auto it = upper_bound(nums.begin(), nums.end(),x);
            long long k = it-nums.begin();
            long long l = k*x-prefix[k];
            long long r = (prefix[n]-prefix[k])-(n-k)*x;
            //  long long cum = prefix[n]-2*prefix[k]-n*x +2*k*x;
            ans.push_back(l+r);
        }
        return ans;
    }
};