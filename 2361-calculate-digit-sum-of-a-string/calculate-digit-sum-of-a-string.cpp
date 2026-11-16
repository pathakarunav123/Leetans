class Solution {
public:
    string digitSum(string s, int k) {
        int n =s.size();
        int ans =0;
        while(s.size()>k){
            int sum=0;
            string str="";
            for(int i=0; i<s.size(); i++){
            int n = s[i]-'0';
            sum+=n;
            if((i+1)%k==0 || i==s.size()-1){
                str += to_string(sum);
                sum=0;
            }    
            }
            s=str;
        }
        return s;
        
    }
};