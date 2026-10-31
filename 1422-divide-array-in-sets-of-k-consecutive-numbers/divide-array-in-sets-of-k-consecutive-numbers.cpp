class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
         if(nums.size() % k != 0) return false;
        map<int,int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        map<int,int>::iterator it;
        it=mp.begin();
        while(it!=mp.end()){
            int x = it->first;
            if(mp.find(x-1)!=mp.end()){
                it++;
                continue;
            }
            int grp=mp[x];
            for(int j=0; j<k; j++){
                int curr = x+j;
                if(mp[curr]<grp) return false;
                mp[curr]-=grp;
            }
            it = mp.begin();

            while(it != mp.end() && it->second == 0) {
                it = mp.erase(it);
            }
        }
        return true;
    }
};