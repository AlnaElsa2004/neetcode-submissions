class Solution {
public:
 
 bool ispal(string s){
    string s2=s;
    reverse(s2.begin(),s2.end());
    return s2==s;
 }

void helper(string s,vector<string> &ans,vector<vector<string>> &res){
    if(s.size()==0){
        res.push_back(ans);
        return;
    }
    for(int i=0;i<s.size();i++){
        string part=s.substr(0,i+1);
        if(ispal(part))
        {ans.push_back(part);
        helper(s.substr(i+1),ans,res);
        ans.pop_back();}
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ans;
        helper(s,ans,res);
        return res;
    }
};
