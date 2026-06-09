class Solution {
public:
    void combnsum(vector<int>& nums,vector<int> &comb,int i,vector<vector<int>> &res,int target){
      if(target == 0){
    res.push_back(comb);
    return;
}

if(i == nums.size() || target < 0){
    return;
}
        comb.push_back(nums[i]);
        //combnsum(nums,comb,i+1,res,target-nums[i]);
        combnsum(nums,comb,i,res,target-nums[i]);
        comb.pop_back();
        combnsum(nums,comb,i+1,res,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        combnsum(nums,comb,0,res,target);
        return res;
    }
};
