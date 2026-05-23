int binary(vector<vector<int>> & matrix, int target, int row){
     int m=matrix.size();
        int n=matrix[0].size();
        int st=0;
        int end=n-1; 
        while(st<=end){
            int mid=st+(end-st)/2;
            if(target==matrix[row][mid]){
                return true;
            }else if(target<matrix[row][mid]){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return false;
}


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int st=0;
        int end=m-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][n-1]){
                return binary(matrix,target,mid);
            }else if(target<=matrix[mid][0]){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return false;
    }
};
