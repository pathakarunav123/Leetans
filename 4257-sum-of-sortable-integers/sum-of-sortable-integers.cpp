class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
         int n = nums.size();
        long long ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;
            int prevLast = INT_MIN;

            for (int start = 0; start < n; start += k) {
                int descents = 0;
                for(int j=start; j<start+k; j++){

                      int next = start + (j - start + 1) % k;
                        if (nums[j] > nums[next]) {
                         descents++;
                              }

                              if (descents > 1) {
                               valid = false;
                                    break;
                                 }



                                  }
                                                     

                int minIdx = start;
                for (int j = start + 1; j < start + k; j++) {
                    if (nums[j] < nums[minIdx]) minIdx = j;
                }

                int first = nums[minIdx];
                int last = nums[start + (minIdx - start + k - 1) % k];

                if (prevLast > first) {
                    valid = false;
                    break;
                }

                prevLast = last;
            }

            if (valid) ans += k;
        }

        return ans;
        
    }
};