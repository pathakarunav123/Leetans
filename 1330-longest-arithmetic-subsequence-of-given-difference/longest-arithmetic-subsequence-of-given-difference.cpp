class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int>mp;
        int ans =0;
        for(int i=0; i<arr.size(); i++){
            int x = arr[i];
            mp[x+difference]=max(mp[x+difference],mp[x]+1);
            ans=max(ans,mp[x+difference]);
        }
        return ans;
        
    }
};