using ll = long long;

class Solution {
public:
    long long countCommas(long long n) {
        ll ans = 0;
        
        for (ll start = 1000, commas = 1;
             start <= n;
             start *= 1000, commas++) {
            
            ll end = min(n, start * 1000 - 1);
            ans += (end - start + 1) * commas;
        }
        
        return ans;
    }
};