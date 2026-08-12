class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>hash;
        int i=0;
        int j=0;
        int maxFreq = 0;
        int count = 0;
        for(int j=0; j<nums.size(); j++){
            hash[nums[j]]++;
            if(hash[nums[j]]<=k){
                count = max(count,j-i+1);
            }
            while(hash[nums[j]]>k && i<j){
                hash[nums[i]]--;
                i++;
            }
        }
        return count;
    }
};