class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
       sort(nums.begin(),nums.end());
       for(int i=0;i<n;i++){
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        int target=-(nums[i]);
        int left=i+1;
        int right=n-1;
        while(left<right){
            if(nums[left]+nums[right]<target){
                left++;
            }else if(nums[left]+nums[right]>target){
                right--;
            }else{
                res.push_back({nums[i],nums[left],nums[right]});
                left++;
                right--;
                while(left<right && nums[left]==nums[left-1]){
                    left++;
                }
                while(left<right && nums[right]==nums[right+1]){
                    right--;
                }
            }
        }
       }
       return res;
    }
};
