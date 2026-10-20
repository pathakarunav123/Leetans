class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>prefix(n+1);
        prefix[0]=0;
        for(int i=1; i<prefix.size(); i++){
            prefix[i]=prefix[i-1]+1LL*nums[i-1];
        }
        long long l=0;
        long long r =0;
        long long freq =0;
        while(r<n){
            int x = nums[r];
           long long cl = x*(r-l)-(prefix[r]-prefix[l]);
            if(cl<=k){
                freq = max(freq,r-l+1);
                r++;
            }else{
                l++;
            }
            
        }
        return freq;
    }
};