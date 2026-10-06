class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_bracket =0;
        int closing_bracket =0;
        for(int i=0; s[i]!='\0'; ++i){
            if(s[i]=='('){
                open_bracket++;
            }else if(open_bracket>0){
                open_bracket--;
            }else{
                closing_bracket++;
            }
        }
        return open_bracket + closing_bracket;
        
    }
};