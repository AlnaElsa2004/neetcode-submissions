class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            int minheight=heights[i];
            for(int j=i;j<n;j++){
                minheight=min(minheight,heights[j]);
                int width=j-i+1;
                int area=minheight*width;
                maxi=max(maxi,area);
            }
        }
        return maxi;
    }
};
