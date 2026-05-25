class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n == 0) return 0;
        unordered_set<char> st;
        int l=0,r=1;
        st.insert(s[0]);
        int maxi=1;
        for(int i=1;i<n;i++){
            if(st.find(s[i])==st.end()){
                st.insert(s[i]);
                maxi=max(maxi,r-l+1);
                r++;
            }else{
                 while(st.find(s[i]) != st.end()) {
                    st.erase(s[l]);
                    l++;
                }

                st.insert(s[i]);

                r++;

                maxi = max(maxi, r - l);
            }
            
        }
        return maxi;
    }
};
