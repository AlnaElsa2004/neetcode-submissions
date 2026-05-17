class Solution {
public:

    string encode(vector<string>& strs) {
      string encoded="";
      for(string x: strs){
        encoded +=to_string(x.size())+'#'+x;
      }
      return encoded;

    }

    vector<string> decode(string s) {
        //string decoded="";
        vector<string> res;
        int n=s.size();
        int i=0;
        while(i<n){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int len=stoi(s.substr(i,j-i));
            string word=s.substr(j+1,len);
            res.push_back(word);
            i=j+1+len;
        }
        return res;


    }
};
