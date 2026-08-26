class Solution {
public:
    int const MOD = 1e9+7;
  //  int solve(int i, vector<int>&dp, string &s){
  //      int n = s.size();
  //      if(i == s.size()) return 1;
  //      if(dp[i]!=-1) return dp[i];
  //      long long one_dig = 0;
  //      long two_dig =0;
  //      int ones = 0;
  //      int twos = 0;
//     if(s[i]!='*'){
//            ones = s[i]-'0';
 //       }
 //       if(i+1<n && s[i]!='*' && s[i+1]!='*'){
  //       twos = (s[i]-'0')*10 + (s[i+1]-'0');
  //      }
 //       if(s[i]!='*'){
  //          if(1<=ones && ones<=9){
  //              one_dig = solve(i+1,dp,s);
   //         }
    //        if(i+1<n && 10<=twos && twos<=26){
    //            two_dig = solve(i+2,dp,s);
     //       }
     //       if(i+1<n && s[i+1]=='*'){ 
     //           if(s[i]=='1'){
      //          two_dig = 9*solve(i+2,dp,s);
      //          }
       //         if(s[i]=='2'){
       //         two_dig = 6*solve(i+2,dp,s);
      //          }
     //       }
     //   }
    //    if(s[i]=='*'){
     //       one_dig = 9*solve(i+1,dp,s);
     //       if(i+1<n && s[i+1]!='*'){
     //           if(s[i+1]=='0' || s[i+1]=='1' || s[i+1]=='2' || s[i+1]=='3'
     //           || s[i+1]=='4' || s[i+1]=='5' || s[i+1]=='6'){
      //          two_dig = 2*solve(i+2,dp,s);
       //         }
       //         if(s[i+1]=='7' || s[i+1]=='8' || s[i+1]=='9'){
        //        two_dig = solve(i+2,dp,s);
         //       }
        //    }
       //     if(i+1<n && s[i+1]=='*'){
       //         two_dig = 15*solve(i+2,dp,s); 

      //      }
      //  }
    //    return dp[i] = (one_dig+two_dig)%MOD;
    //}
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1,-1);
        dp[n]=1;
      for(int i=n-1;  i>=0; i--){
        int ones = 0;
        if(s[i]!='*'){
            ones = s[i] -'0';
        }
        int twos = 0;
        if(i+1<n && s[i]!='*' && s[i+1]!='*'){
           twos=(s[i]-'0')*10+s[i+1]-'0';
        }

        long long one_dig =0;
        long long two_dig =0;
        if(s[i]!='*'){
             if(1<=ones && ones<=9){
                one_dig = dp[i+1];
             }
          if(i+1<n && 10<=twos && twos<=26){
                 two_dig = dp[i+2];
             }
              if(i+1<n && s[i+1]=='*'){ 
                  if(s[i]=='1'){
                  two_dig = 9LL*dp[i+2];
                  }
                  if(s[i]=='2'){
                 two_dig = 6LL*dp[i+2];
                  }
              }
        }
        if(s[i]=='*'){
             one_dig = 9LL*dp[i+1];
             if(i+1<n && s[i+1]!='*'){
                if(s[i+1]=='0' || s[i+1]=='1' || s[i+1]=='2' || s[i+1]=='3'
                  || s[i+1]=='4' || s[i+1]=='5' || s[i+1]=='6'){
                 two_dig = 2LL*dp[i+2];
                 }
                  if(s[i+1]=='7' || s[i+1]=='8' || s[i+1]=='9'){
                  two_dig = dp[i+2];
                 }
             }
             if(i+1<n && s[i+1]=='*'){
                 two_dig = 15LL*dp[i+2]; 

             }
          }
          dp[i] = (one_dig+two_dig)%MOD;
      }
      return dp[0];
    }
};