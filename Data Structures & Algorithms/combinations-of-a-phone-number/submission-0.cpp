class Solution {
public:
 vector<string> res;
    unordered_map<char,string> digittostr={
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
    void helper(string digits,int i,string &curstr,vector<string> &res){
         if(curstr.size()==digits.size()){
            res.push_back(curstr);
            return;
         }
           string letters = digittostr[digits[i]];

        for (char ch : letters) {
            curstr.push_back(ch);          // choose
            helper(digits, i + 1, curstr, res); // recurse
            curstr.pop_back();             // backtrack
        }
    }

    
    vector<string> letterCombinations(string digits) {
        string curstr="";
        vector<string> res;
        if(digits!="")
        helper(digits,0,curstr,res);
        return res;
    }
};

