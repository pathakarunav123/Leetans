class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n+1);
        prefix[0]=0;
        for(int i=1; i<prefix.size(); i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        int len = n+1;
        for(int j=1; j<prefix.size(); j++){
            int x = prefix[j]-target;
            auto it = upper_bound(prefix.begin(),prefix.begin()+j,x);
            if(it!=prefix.begin()){
                --it;
            int i = it-prefix.begin();
            len = min(len,j-i);
            }
        }
        if(len==n+1)return 0;
        return len;
    }
};