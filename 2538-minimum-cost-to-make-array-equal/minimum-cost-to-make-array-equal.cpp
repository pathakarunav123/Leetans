class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        int m = cost.size();
        vector<pair<int,int>>arr;
        for(int i=0; i<nums.size(); i++){
            arr.push_back({nums[i],cost[i]});
        }
        sort(arr.begin(),arr.end());
        vector<long long>prefixCost(n+1,0);
        vector<long long>prefixWeight(n+1,0);
        vector<long long>sortedNum(n);
        for(int i=1; i<prefixCost.size(); i++){
            prefixCost[i] = prefixCost[i-1]+1LL*arr[i-1].second;
            prefixWeight[i]=prefixWeight[i-1]+ 1LL*arr[i-1].first*arr[i-1].second;
            sortedNum[i-1]=1LL*arr[i-1].first;
        }

        long long ans = LLONG_MAX;
        for(int i=0; i<sortedNum.size(); i++){
            long long x = sortedNum[i];
            auto it = lower_bound(sortedNum.begin(),sortedNum.end(),x);
            long long k = it-sortedNum.begin();
            long long cl = prefixCost[k]*x - prefixWeight[k];
            long long cr = (prefixWeight[n]-prefixWeight[k]) - (prefixCost[n]-prefixCost[k])*x;
            ans = min(ans,cl+cr); 
        }
        return ans;
    }
};