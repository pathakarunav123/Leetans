class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>mp;
        unordered_map<int,int>need;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
            need[nums[i]]=0;
        }
        for(int i=0; i<nums.size();i++){
            int x = nums[i];
            if(mp[x]==0) continue;
            if(need[x]>0){
                mp[x]--;
                need[x]--;
                need[x+1]++;
            }
            else if(need[x]==0){
              if(mp[x+1]>0 && mp[x+2]>0){
                mp[x]--;
                mp[x+1]--;
                mp[x+2]--;
                need[x+3]++;
            }else{
                return false;
            }
            }
        }
        return true;
    }
};