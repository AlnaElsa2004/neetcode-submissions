class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> tar;
        int n=triplets.size();
        int max1=0;
        int max2=0;
        int max3=0;
        for(int i=0;i<n;i++){
          if(triplets[i][0] <= target[0] &&
                triplets[i][1] <= target[1] &&
                triplets[i][2] <= target[2]){
           max1=max(max1,triplets[i][0]);}
           else{
            continue;
           }
        }
        tar.push_back(max1);
        for(int i=0;i<n;i++){
       if(triplets[i][0] <= target[0] &&
                triplets[i][1] <= target[1] &&
                triplets[i][2] <= target[2]){
        max2=max(max2,triplets[i][1]);
    }else{
        continue;
    }
    }
    tar.push_back(max2);
    for(int i=0;i<n;i++){
       if(triplets[i][0] <= target[0] &&
                triplets[i][1] <= target[1] &&
                triplets[i][2] <= target[2]){
        max3=max(max3,triplets[i][2]);
    }else{
        continue;
    }
    }
    tar.push_back(max3);
    return tar==target;
    }
};
