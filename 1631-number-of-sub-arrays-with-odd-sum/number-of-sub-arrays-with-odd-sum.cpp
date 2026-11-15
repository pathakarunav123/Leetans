class Solution {
public:
    int MOD = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int>prefix(n+1);
        prefix[0]=0;
        for(int i=1; i<prefix.size(); i++){
            prefix[i]=prefix[i-1]+arr[i-1];
        }
        int even=1;
        int odd =0;
        int ans=0;
        for(int i=1; i<prefix.size(); i++){
            if(prefix[i]%2!=0){
                ans=(ans+even)%MOD;
                odd++;
            }else{
                ans=(ans+odd)%MOD;
                even++;
            }
        }
        return ans%MOD;
    }
};