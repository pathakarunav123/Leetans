class Solution {
public:
    bool checkDivisibility(int n) {
        int sum =0;
        int mul = 1;
        int x=n;
        while(n!=0){
            int digit = n%10;
            sum +=digit;
            mul*=digit;
            n=n/10;
        }
         if(x%(sum+mul)){
            return false;
         }
         return true;
        
    }
};