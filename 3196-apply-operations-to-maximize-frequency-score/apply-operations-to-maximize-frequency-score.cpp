class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>prefix(n+1);
        prefix[0]=0;
        for(int i=1; i<prefix.size();i++){
            prefix[i]=prefix[i-1]+1LL*nums[i-1];
        }
        long long l=0;
        long long freq = LLONG_MIN;
        for(int r=0; r<nums.size(); r++){
            int m = l+(r-l)/2;
            int x=nums[m];
            long long cl = 1LL*x*(m-l)-(prefix[m]-prefix[l]);
            long long cr =(prefix[r+1]-prefix[m+1])-1ll*(r-m)*x;
            long long ct = cl+cr;
            while(ct>k){
                l++;
                m = l+(r-l)/2;
                cl = 1LL*x*(m-l)-(prefix[m]-prefix[l]);
                cr=(prefix[r+1]-prefix[m+1])-1LL*(r-m)*x;
                ct = cl+cr;
            }
            freq = max(freq,r-l+1);
        }
        return freq;
        
    }
};