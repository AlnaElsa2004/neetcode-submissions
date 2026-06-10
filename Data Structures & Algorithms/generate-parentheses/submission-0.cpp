class Solution {
public:
    void par(string &nums,int open,int close,int n, vector<string> &res){
        if (open == n && close == n){
            res.push_back(nums);
            return;
        }
      if(open<n){
        nums+="(";
        par(nums,open+1,close,n,res);
        nums.pop_back();
      }
      if(close<open){
        nums+=")";
        par(nums,open,close+1,n,res);
        nums.pop_back();
      }

    }
    vector<string> generateParenthesis(int n) {
        string nums="";
        vector<string> res;
        par(nums,0,0,n,res);
        return res;
    }
};
