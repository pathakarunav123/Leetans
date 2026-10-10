class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        vector<long long>prefix(nums.size()+1);
        prefix[0]=0;
        long long totalSum =0;
        for(int i=0; i<nums.size(); i++){
            totalSum+=nums[i];
        }
        int rem= totalSum%p;
        if(rem==0)return 0;
        for(int i=1; i<prefix.size(); i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        int min_len = nums.size()+1;
        unordered_map<int,int>mp;
        mp[0]=0;
        for(int i=0; i<prefix.size(); i++){
            int p_curr = prefix[i]%p;
            int p_prev = (p_curr-rem+p)%p; //for void negative
            if(mp.find(p_prev)!=mp.end()){
                min_len = min(min_len,i-mp[p_prev]);
            }
            mp[p_curr]=i;
        }
        if(min_len>=nums.size())return -1;
        return min_len;
    }
};