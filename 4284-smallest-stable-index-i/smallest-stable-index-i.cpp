class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n =nums.size();
        vector<int>pref(n);
        pref[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            pref[i] = min(pref[i+1],nums[i]);
        }
            int maxi = -1e9;
            for(int j=0; j<nums.size(); j++){
                maxi = max(maxi,nums[j]);
                if(maxi-pref[j]<=k){
                    return j;
                }
            }
        
        return -1;
    }
};