class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10){
            return false;
        }
        int alice_move=1;
        int bob_move =0;
        int temp=10;
        while(n>=temp){
             n =n-temp;
              temp--;
            if(bob_move==0){
                bob_move=1;
                alice_move=0;
            }else{
                alice_move=1;
                bob_move=0;
            }
            }
       return bob_move;
        
    }
};