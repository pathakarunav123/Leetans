class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n+1,0);
        prefix[0]=0;
        for(int i=1; i<prefix.size(); i++){
            prefix[i]+=prefix[i-1]+nums[i-1];

        }
        int answer =-1;
        for(int i=0; i<nums.size(); i++){
          int left=prefix[i-1+1]-prefix[0];
            int right = prefix[n]-left-nums[i];
            if(left==right){
                answer=i;
                break;
            }
        }
        return answer;
        
    }
};