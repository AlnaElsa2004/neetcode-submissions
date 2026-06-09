
class Solution {
public:
void getsub(vector<int>& nums,vector<int>& ans,int i,vector<vector<int>> &res){
    if(i==nums.size()){
        res.push_back(ans);
        return;
    }
    ans.push_back(nums[i]);
    getsub(nums,ans,i+1,res);
    ans.pop_back(); 
    int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[idx-1]) {
            idx++;
        }

        // Skip current value entirely
       
    getsub(nums,ans,idx,res);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
       vector<int> ans;
       getsub(nums,ans,0,res);
       return res;

    }
};
