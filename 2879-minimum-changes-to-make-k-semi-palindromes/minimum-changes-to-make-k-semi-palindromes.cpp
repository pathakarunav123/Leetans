class Solution {
public:
        int palindrome(int l, int r, int d, string &s){
            int len = r-l+1;
            int m = len/d;
            int count =0;
            for(int g=0; g<d; g++){
                for(int t=0; t<m/2; t++){
                    int left=l+g+t*d;
                    int right = l+g+(m-1-t)*d;
                    if(s[left]!=s[right]){
                        count++;
                    }
                }
            }
            return count;
        }
        int solve(int i, int j,vector<vector<int>>&dp, vector<vector<int>>&cost){
            if(i==0){
                if(j==0){
                    return 0;
                }
                return 1e9;
            }
            if(j == 0 && i!=0) return 1e9;
            if(i < 2*j) return 1e9;
            if(dp[i][j]!=-1) return dp[i][j];
              int ans =1e9;
            for(int p=2*(j-1); p<=(i-2); p++){
                int prev = solve(p,j-1,dp,cost);
                if(prev!=1e9){
                    ans = min(ans,cost[p][i-1]+prev);
                }
            }
            return dp[i][j]=ans;
        }
    int minimumChanges(string s, int k) {
        int n =s.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        for(int l=0; l<n; l++){
            for(int r=l+1;r<n; r++){
                int len = r-l+1;
                cost[l][r]=1e9;
                for(int d=1; d<len; d++){
                    if(len%d!=0) continue;
                    int curr=palindrome(l,r,d,s);
                    cost[l][r]=min(cost[l][r],curr);
                }
            }
        }
        int ans =solve(n,k,dp,cost);
        return ans;
    }
};