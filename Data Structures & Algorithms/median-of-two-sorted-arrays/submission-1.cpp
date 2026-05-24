class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int n=nums1.size();
      int m=nums2.size();
      int i=0,j=0,k=0,p=m+n;
      int nums[p];
      while(i<n && j<m){
        if(nums1[i]<nums2[j]){
            nums[k]=nums1[i];
            i++;
            k++;
        }else{
            nums[k]=nums2[j];
            k++;
            j++;
        }
      } while(i!=n){
            nums[k]=nums1[i];
            k++;
            i++;
       
         } 
         while(j!=m){
            nums[k]=nums2[j];
            k++;
            j++;
         }
         
         
         if(p % 2 == 0) {

            int mid1 = p / 2;
            int mid2 = mid1 - 1;

            return (nums[mid1] + nums[mid2]) / 2.0;
        }
        else {

            int mid = p / 2;

            return nums[mid];
        } 
    }
};
