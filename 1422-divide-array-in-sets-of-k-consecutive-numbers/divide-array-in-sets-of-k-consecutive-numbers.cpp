class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {

        if(nums.size() % k != 0) return false;

        map<int,int> mp;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        while(!mp.empty()) {

            int x = mp.begin()->first;
            int groups = mp.begin()->second;

            for(int j = 0; j < k; j++) {

                int curr = x + j;

                if(mp[curr] < groups) {
                    return false;
                }

                mp[curr] -= groups;

                if(mp[curr] == 0) {
                    mp.erase(curr);
                }
            }
        }

        return true;
    }
};