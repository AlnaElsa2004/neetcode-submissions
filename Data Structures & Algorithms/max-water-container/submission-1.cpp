class Solution {
public:
    int maxArea(vector<int>& heights) {
       int maxi=0;
       for(int i=0;i<heights.size();i++){
        for(int j=i+1;j<heights.size();j++){
            int pro=min(heights[i],heights[j]);
            pro*=(j-i);
            maxi=max(maxi,pro);
        }
       }
       return maxi; 
    }
};
