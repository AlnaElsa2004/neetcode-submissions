class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if((n%groupSize)!=0){
            return false;
        }
        unordered_map<int,int>mp;
        for(int x:hand){
            mp[x]++;
        }
        sort(hand.begin(),hand.end());
        for(int i=0;i<n;i++){
         if(mp[hand[i]]==0){
            continue;
         }
         for(int j=0;j<groupSize;j++){
            int x=hand[i]+j;
            if(mp[x]==0){
                return false;
            }
            mp[x]--;
         }
        }
        return true;
    }
};
