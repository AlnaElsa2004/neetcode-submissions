class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      if(nums1.size()>nums2.size()){
        swap(nums1,nums2);
      }
      int x=nums1.size();
      int y=nums2.size();
      int left=0;
      int right=x;
      while(left<=right){
        int partx=(left+right)/2;
        int party=(x+y)/2-partx;
        int maxleftx=(partx==0)? INT_MIN:nums1[partx-1];
        int maxlefty=(party==0)? INT_MIN:nums2[party-1];
        int minrightx=(partx==x)? INT_MAX:nums1[partx];
        int minrighty=(party==y)? INT_MAX:nums2[party];
        if(maxleftx<=minrighty && maxlefty<=minrightx){
            if((x+y)%2==0){
                return(max(maxleftx,maxlefty)+min(minrightx,minrighty))/2.0;
            }else{
               return min(minrightx, minrighty);
            }
        }else if(maxleftx>minrighty){
            right=partx-1;
        }else{
            left=partx+1;
        }
      }
      return 0.0;
    }
};
