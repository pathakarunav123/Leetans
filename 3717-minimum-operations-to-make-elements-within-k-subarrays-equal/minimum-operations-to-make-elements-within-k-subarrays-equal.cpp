class Solution {
public:
    class MedianWindow {
private:
    multiset<int> L, R;
    long long sumL = 0;
    long long sumR = 0;
    void moveLtoR() {
        auto it = prev(L.end());

        int val = *it;

        L.erase(it);
        sumL -= val;

        R.insert(val);
        sumR += val;
    }
    void moveRtoL() {
        auto it = R.begin();

        int val = *it;

        R.erase(it);
        sumR -= val;

        L.insert(val);
        sumL += val;
    }

    void rebalance() {
        while (L.size() > R.size() + 1) {
            moveLtoR();
        }

        while (L.size() < R.size()) {
            moveRtoL();
        }
    }

public:
    void insert(int x) {
        if (L.empty() || x <= *L.rbegin()) {
            L.insert(x);
            sumL += x;
        }
        else {
            R.insert(x);
            sumR += x;
        }

        rebalance();
    }

    void erase(int x) {
        auto it = L.find(x);

        if (it != L.end()) {
            L.erase(it);
            sumL -= x;
        }
        else {
            it = R.find(x);

            if (it != R.end()) {
                R.erase(it);
                sumR -= x;
            }
        }

        rebalance();
    }

    long long getCost() {
        if (L.empty()) return 0;

        long long median = *L.rbegin();

        long long leftCost =
            median * (long long)L.size() - sumL;

        long long rightCost =
            sumR - median * (long long)R.size();

        return leftCost + rightCost;
    }

    int getMedian() {
        return *L.rbegin();
    }
};  
    
vector<long long> getWindowCosts(vector<int>& nums, int x) {
    int n = nums.size();

    MedianWindow win;
    vector<long long> cost;

    // First window
    for (int i = 0; i < x; i++) {
        win.insert(nums[i]);
    }

    cost.push_back(win.getCost());

    for (int i = x; i < n; i++) {
        win.erase(nums[i - x]);
        win.insert(nums[i]);

        cost.push_back(win.getCost());
    }

    return cost;
}

    long long solve(int i, int j, vector<long long>&cost, vector<vector<long long>>&dp,int x,vector<int>&nums){
        if(j==0){
            return 0;
        }
        if(i>=cost.size() && j!=0) return LLONG_MAX/4;
        if(dp[i][j]!=-1) return dp[i][j];
        long long select = cost[i]+solve(i+x,j-1,cost,dp,x,nums);
        long long skip = solve(i+1,j,cost,dp,x,nums);
        return dp[i][j]=min(select,skip);
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
         vector<long long> cost = getWindowCosts(nums, x);
        vector<vector<long long>>dp(n+1,vector<long long>(k+1,-1));
        long long ans = solve(0,k,cost,dp,x,nums);
        return ans;
    }
};