class Solution {
public:
    long long minimumCost(string s) {
        long long n = s.size();
        long long ans = 0;
        for(int i=1; i<s.size(); i++){
            if(s[i]!=s[i-1]){
                ans+=min(1LL*i,n-1LL*i);
            }
        }
        return ans;
    }
};