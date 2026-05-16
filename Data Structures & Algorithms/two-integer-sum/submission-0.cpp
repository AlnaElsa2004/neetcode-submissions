class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     int sum=target;
     int n=nums.size();
     vector<int> no;
     for(int i=0;i<n;i++){
        int diff=sum-nums[i];
        for(int j=i+1;j<n;j++){
            if(nums[j]==diff){
                no.push_back(i);
                no.push_back(j);
            }
        }
     }
     
     return no;
    }
};
