
class Solution {
public:
    int countSubstrings(string s) {
        int k=0;
        int maxlen=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            
                int l=i;
                int r=i;
                while(l>=0 && r<n && s[l]==s[r]){
                   k++;
                    l--;
                    r++;
                }
            
                 l=i;
                 r=i+1;
                while(l>=0 && r<n && s[l]==s[r]){
                    k++;
                    l--;
                    r++;
                }
            
        }
        return k;
    }
};
