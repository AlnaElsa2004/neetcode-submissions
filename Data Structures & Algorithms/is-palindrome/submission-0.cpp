class Solution {
public:
    bool isPalindrome(string s) {
        string ss;
        int n=s.length();
        for(char c : s) {
            if(isalnum(c)) {
                ss += tolower(c);
            }
        }
        int n2=ss.length();
        for(int i=0;i<n2/2;i++){
            if(ss[i]==ss[n2-i-1]){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
};
