class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        int maxlen=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            
                int l=i;
                int r=i;
                while(l>=0 && r<n && s[l]==s[r]){
                    if((r-l+1)>maxlen){
                        res=s.substr(l,r-l+1);
                        maxlen=r-l+1;
                    }
                    l--;
                    r++;
                }
            
                 l=i;
                 r=i+1;
                while(l>=0 && r<n && s[l]==s[r]){
                    if((r-l+1)>maxlen){
                        res=s.substr(l,r-l+1);
                        maxlen=r-l+1;
                    }
                    l--;
                    r++;
                }
            
        }
        return res;
    }
};
