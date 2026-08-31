class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[]
        (vector<int>&a , vector<int>&b){
            return a[1]>b[1];
        });
        int n = boxTypes[0].size()-1;
        int ans = 0;
        for(int i=0; i<boxTypes.size(); i++){
           int boxes = min(truckSize,boxTypes[i][0]);
           ans += boxes*boxTypes[i][1];
           truckSize-=boxes;
        }
        return ans;  
    }
};