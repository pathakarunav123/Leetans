class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        int planted =0;
        for(int i=0; i<flowerbed.size(); i++){
            int left = (i==0 || flowerbed[i-1]==0);
            int right = (i==m-1 || flowerbed[i+1]==0);
            if(flowerbed[i]==0 && left && right){
                flowerbed[i]=1;
                n--;
            }
        }
        if(n<=0){
            return true;
        }
        return false;
    }
};