class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        unordered_map<char,int> mp;
        int l=0,r=0,maxlen=0;
        int maxi=0;
        while(r<n){
            mp[s[r]]++;
            maxlen=max(maxlen,mp[s[r]]);
            if((r-l+1-maxlen)<=k){
                maxi=max(r-l+1,maxi);
                
            }else{
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return maxi;
    }
};
