class Solution {
public:
int product(int x){
    int ans = 1;
        while(x!=0){
            int digit = x%10;
            ans *= digit; 
            x=x/10;
        } 
        return ans;
}
    int smallestNumber(int n, int t) {
        int P[2] = {product(n/10),product(n/10+1)};
        int z1 = (n/10+1)*10;
       for(int z=n; z<n+10; z++){
        int p =P[z>=z1], d = z%10;
        if(p*d%t==0){
            return z;
        }
       }
       return 0;
    }
};