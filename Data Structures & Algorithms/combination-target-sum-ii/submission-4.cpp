class Solution {
public:
set<vector<int>> s;
    void combnsum(vector<int>& nums,vector<int> &comb,int i,vector<vector<int>> &res,int target){
      if(target == 0){
        if(s.find(comb)==s.end()){
    res.push_back(comb);
        s.insert(comb);}
    return;
}

if(i == nums.size() || target < 0){
    return;
}
        comb.push_back(nums[i]);
        combnsum(nums,comb,i+1,res,target-nums[i]);
        //combnsum(nums,comb,i,res,target-nums[i]);
        comb.pop_back();
        // Skip all duplicates of nums[i]
        int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[idx-1]) {
            idx++;
        }

        // Skip current value entirely
        combnsum(nums, comb, idx, res, target);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
          //set<int> no(nums.begin(), nums.end());
        //vector<int> num(no.begin(), no.end());
   sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> comb;
        combnsum(nums,comb,0,res,target);
        return res;
    }
};
