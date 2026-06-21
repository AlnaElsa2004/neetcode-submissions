class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=*max_element(nums.begin(),nums.end());
        int curmin=1;
        int curmax=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                curmin=1;
                curmax=1;
                continue;
            }
            int temp=nums[i]*curmax;
            curmax=max(nums[i]*curmax,max(nums[i]*curmin,nums[i]));
            curmin=min(temp,min(nums[i]*curmin,nums[i]));
            res=max(curmax,res);
        }
        return res;
    }
};
