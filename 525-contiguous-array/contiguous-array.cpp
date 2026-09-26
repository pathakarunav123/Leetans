class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        vector<int>prefix(n+1);
        prefix[0]=0;
        mp[0]=0;
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                nums[i]=-1;
            }
        }
        for(int i=1; i<prefix.size(); i++){
            prefix[i]+=prefix[i-1]+nums[i-1];
        }
        for(int i=0; i<prefix.size(); i++){
            if(mp.find(prefix[i])!=mp.end()){
                ans = max(ans,i-mp[prefix[i]]);
            }else{
                mp[prefix[i]]=i;
            }
        }
        return ans;
    }
};