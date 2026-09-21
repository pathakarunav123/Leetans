class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>s;
        for(int i=n;i>=1; i--){
            if(i%3==0 && i%5==0){
                s.push_back("FizzBuzz");
            }else if(i%3==0){
                s.push_back("Fizz");
            }else if(i%5==0){
               s.push_back("Buzz");
            }else{
                    s.push_back(to_string(i));        
                     }
             }
     reverse(s.begin(),s.end());
     return s;
    }
};