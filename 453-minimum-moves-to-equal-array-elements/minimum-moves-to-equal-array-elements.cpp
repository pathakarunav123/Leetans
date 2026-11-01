class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
       int mini =INT_MAX;
       vector<int>prefix(n+1);
       prefix[0]=0;
       for(int i=1; i<prefix.size(); i++){
        prefix[i] = prefix[i-1]+nums[i-1];
        mini = min(mini,nums[i-1]);
       }
       return (prefix[n]-prefix[0])-n*mini;
    }
};