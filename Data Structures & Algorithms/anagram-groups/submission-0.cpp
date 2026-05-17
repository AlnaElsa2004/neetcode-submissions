class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> sorts=strs;       
        for(string &word: sorts){
            sort(word.begin(),word.end());
        }
        vector<vector<string>> res;
        vector<bool> visited(strs.size(),false);
        for(int i=0;i<sorts.size();i++){
            if(visited[i]){
                continue;
            }
            vector<string> gp;
            gp.push_back(strs[i]);
            visited[i]=true;
            for(int j=i+1;j<sorts.size();j++){
                if(sorts[i]==sorts[j]){
                    gp.push_back(strs[j]);
                    visited[j]=true;

                }
            }
            res.push_back(gp);
        }
      return res;
    }
};
