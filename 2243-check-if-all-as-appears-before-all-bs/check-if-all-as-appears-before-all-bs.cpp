class Solution {
public:
    bool checkString(string s) {
        bool valid=false;
        if(s.find_first_not_of('a') == std::string::npos) return true;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='b'){
                valid=true;
            }

            if(valid==true && s[i]=='a'){
                return false;
            }
        }
        return valid;
    }
};