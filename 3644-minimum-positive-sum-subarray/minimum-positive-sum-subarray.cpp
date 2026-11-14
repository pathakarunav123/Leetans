class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        vector<int>ans(nums.size()+1,0);
        bool isFound = false;
        int i =0;
        int j =0;
        for(i=0; i<nums.size(); i++){
            ans[i+1] = ans[i] + nums[i];
        }
        int mini = INT_MAX;
        for( int j = l; j<=r; j++ ){
            for(int k = 0; j+k<=nums.size(); k++){
                int sum = ans[j+k] - ans[k];
                if(sum>0){
                    mini = min(sum,mini);
                    isFound = true;
                }

            }
            
        }
        if(isFound==true){
            return mini;
        }else{
            return -1;
        }
        
    }
};