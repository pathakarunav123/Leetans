class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n= nums.size();
       unordered_set<int>st;
    //    st.insert(0);
       int j= *max_element(nums.begin(),nums.end());
    //    if(k>max)
        for(int i=0;i<n;i++){
            if(nums[i]%k==0){
                st.insert(nums[i]/k);
            }


        }

        for(int i=1;i<=j+1;i++){
            if(st.find(i)!=st.end()){
                continue;
            }
            else return i*k;
        }
        return k;
        
    }
};