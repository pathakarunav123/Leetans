class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int  n = nums.size();
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }else{
                nums[i]=1;
            }
        }
        unordered_map<int,int>mp;
        vector<int>prefix(n+1);
        prefix[0]=0;
        for(int i=1; i<prefix.size(); i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        int ans =0;
        for(int i=0; i<prefix.size(); i++){
            int j = prefix[i]-k;
            if(mp.find(j)!=mp.end()){
                ans+=mp[j];
            }
            mp[prefix[i]]++;
        }
        return ans;
        
    }
};