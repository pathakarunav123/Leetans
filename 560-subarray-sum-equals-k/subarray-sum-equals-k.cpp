class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int answer =0;
        vector<int>prefix(nums.size()+1);
        prefix[0]=0;
        unordered_map<int,int>mp;
       // mp[0]=1;
        for(int i=1; i<prefix.size(); i++){
            prefix[i]+=prefix[i-1]+nums[i-1];
        }

        for(int i=0; i<prefix.size(); i++){
            int j = prefix[i]-k;
            if(mp.find(j)!=mp.end()){
                answer+=mp[j];
            }
                mp[prefix[i]]++;
            
        }
        return answer;
        
    }
};