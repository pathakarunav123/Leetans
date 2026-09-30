class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int>prefix(n+1);
        prefix[0]=0;
        unordered_map<int,int>mp;
        int answer=0;
        for(int i=1; i<prefix.size(); i++){
            prefix[i]+=prefix[i-1]+nums[i-1];
        }
        for(int i=0; i<prefix.size(); i++){
            int j = prefix[i]-goal;
            if(mp.find(j)!=mp.end()){
                answer+=mp[j];
            }
            mp[prefix[i]]++;
        }
        return answer;
        
    }
};