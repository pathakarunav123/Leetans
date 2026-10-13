class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long>sum(n);
        for(int i=0; i<nums.size(); i++){
            sum[i]=1ll*nums[i]*nums[i];
        }
        sort(sum.begin(),sum.end());
        long long pos =0;
        long long neg =0;
        for(int i=0; i<n-(n+1)/2; i++){
            neg+=sum[i];
        }
        for(int i=n-(n+1)/2; i<n; i++){
            pos+=sum[i];
        }
        return pos - neg;
        
    }
};