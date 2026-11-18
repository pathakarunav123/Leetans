class Solution {
public:
    int minChanges(string s) {
        int i=0;
        int change=0;
        while(i<s.size()){
            if(i+1<s.size() && s[i]!=s[i+1]){
                change++;
            }   
            i+=2;
        }
        return change;   
    }
};