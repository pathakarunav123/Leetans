class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int row=0; row<image.size();row++){
            int i = 0;
            int j = image[row].size()-1;
                while(i<=j){
                    swap(image[row][i],image[row][j]);
                    i++;
                    j--; 
            }
        }
        for(int i=0; i<image.size(); i++){
            for(int j=0; j<image[i].size();j++){
                if(image[i][j]^1){
                    image[i][j]=1;
                }else{
                    image[i][j]=0;
                }
            }
        }
        return image;
    }
};