class Solution {
public:
    bool isAnagram(string s, string t) 
     {  //sort(s.begin(),s.end());
        //sort(t.begin(),t.end());
        unordered_map<char,int> freq;
        unordered_map<char,int> fre1;
        if(s.length()==t.length()){
            for(int i=0;i<s.length();i++){
                freq[s[i]]++;
            }
            for(int i=0;i<t.length();i++){
                fre1[t[i]]++;
            }
            for(int i=0;i<s.length();i++){
                if(freq[s[i]]!=fre1[s[i]]){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};
