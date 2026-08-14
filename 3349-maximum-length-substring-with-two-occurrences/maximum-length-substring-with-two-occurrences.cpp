class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>hash;
        int i =0;
         int ans = -1e9;
        for(int j=0;j<s.size();j++){
            hash[s[j]]++;
            while(hash[s[j]]>2 && i<j){
                hash[s[i]]--;
                i++;
            }
            
                ans = max(ans,j-i+1);
            
        }        
        return ans;
    }
};