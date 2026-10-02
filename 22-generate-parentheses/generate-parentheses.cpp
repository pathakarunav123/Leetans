class Solution {
public:
void backtrack(int i ,int open, int close , int n , vector<string>&ans,string&s){
    if(i==2*n){
        ans.push_back(s);
        return;
    }
    if(open<n){
        s.push_back('(');
        backtrack(i+1,open+1,close,n,ans,s);
         s.pop_back();
    }
    if(close<open){
        s.push_back(')');
        backtrack(i+1,open,close+1,n,ans,s);
         s.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
       string s = "";
        vector<string>ans;
        backtrack(0,0,0,n,ans,s);
        return ans;
    }
};