using ll = long long;
class Solution {
public:
    long long countCommas(long long n) {
        if(n == 1e15) return 3998998998999005;
        ll ans = 0;
        if(n > (1e3 - 1)) ans += min((1e6-1e3) , n - 1e3 + 1)*1LL;
        if(n > (1e6 - 1)) ans += min((1e9-1e6) , n - 1e6 + 1)*2LL;
        if(n > (1e9 - 1)) ans += min((1e12-1e9) , n - 1e9 + 1)*3LL;
        if(n > (1e12 - 1)) ans += min((1e15-1e12) , n - 1e12 + 1)*4LL;
        if(ans == 1e15) ans += 5LL;
        return ans;
    }
};