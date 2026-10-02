class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prefix(n+1,0);
        for(int i=1; i<prefix.size(); i++){
            prefix[i]+=prefix[i-1]+nums[i-1];
        }
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=0; i<prefix.size(); i++){
            int j = ((prefix[i] % k) + k) % k; //avoid negative number
            if(mp.find(j)!=mp.end()){
                ans+=mp[j];
            }
            mp[j]++;
        }
        return ans;
        
    }
};