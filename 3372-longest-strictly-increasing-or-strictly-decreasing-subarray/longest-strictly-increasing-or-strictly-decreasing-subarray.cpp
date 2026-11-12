class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
    int n= nums.size();
    int count1=1;
    int count2=1;
    int ans=1;
    for(int i=1;i<n;i++){
        if(nums[i]>nums[i-1]){
            count1++;
            count2=1;
        }
        else if(nums[i]<nums[i-1]){
            count2++;
            count1=1;
        }
        else{
            count1=1;
        count2=1;
        }
        

        ans= max(ans, max(count1,count2));
    }
    return ans;
    }
};