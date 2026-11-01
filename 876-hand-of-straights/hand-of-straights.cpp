class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>mp;
        for(int i=0; i<hand.size(); i++){
            mp[hand[i]]++;
        }
        while(!mp.empty()){
            int x = mp.begin()->first;
            int group=mp.begin()->second;
            for(int j=0; j<groupSize; j++){
                int curr = x+j;
                if(mp[curr]<group){
                    return false;
                }
                mp[curr]-=group;
                if(mp[curr]==0){
                    mp.erase(curr);
                }
            }

        }
        return true;        
    }
};