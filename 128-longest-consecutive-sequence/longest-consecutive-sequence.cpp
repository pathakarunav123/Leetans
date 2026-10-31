class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<long long>mp;
        for(int i=0; i<nums.size(); i++){
           mp.insert(nums[i]);
        }
        long long ans = 0;
        std::unordered_set<long long>::iterator it = mp.begin();
        while(it!=mp.end()){
            long long x = *it;
            if(mp.find(x-1)!=mp.end()){
               it++;
               continue;
            }
            long long len =0;
                while(mp.find(x + 1) != mp.end()){
                        len++;
                        x++;
                }
            ans = max(len+1,ans);
            it++;
            }
      return ans;
        
    }
};