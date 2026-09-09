class Solution {
public:
    int solve(int i, vector<int>&dp,vector<vector<int>>&books, int shelfWidth){
        if(i==books.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int max_height = -1e9;
        int ans = 1e9;
        int book_width =0;
        for(int j=i; j<books.size(); j++){
            book_width +=books[j][0];
            if(book_width<=shelfWidth){
                 max_height = max(max_height,books[j][1]);
                ans = min(ans,max_height+solve(j+1,dp,books,shelfWidth));
            }
        }
        return dp[i]=ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n =books.size();
        vector<int>dp(n+1,-1);
        int ans = solve(0,dp,books,shelfWidth);
        return ans;
    }
};