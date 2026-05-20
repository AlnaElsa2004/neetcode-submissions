class Solution {
public:
    int maxArea(vector<int>& heights) {
       int maxi=0;
       int left=0;
       int n =heights.size();
       int right=n-1;
       while(left<right){
        int pro=(right-left)*min(heights[left],heights[right]);
        maxi=max(maxi,pro);
        if(heights[left]<=heights[right]){
            left++;
        }else{
            right--;
        }
       }
       return maxi;
    }
};
