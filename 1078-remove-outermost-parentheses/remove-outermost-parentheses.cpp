class Solution {
public:
    string removeOuterParentheses(string s) {
        int bal =0;
        string ans = "";
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                if(bal>0){
                    ans.push_back(s[i]);
                }
                 bal++;
            }else{
                bal--;
                if(bal>0){
                    ans.push_back(s[i]);
                }
            }
                
        }
        return ans;
        
    }
};