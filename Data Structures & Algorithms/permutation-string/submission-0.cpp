bool allZero(unordered_map<char,int>& freq) {

        for(auto p : freq) {
            if(p.second != 0) {
                return false;
            }
        }

        return true;
    }


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        if(n>m) return false;
        unordered_map<char,int> freq;
        for(int i=0;i<n;i++){
            freq[s1[i]]++;
        }
        int left=0;
        int right=n-1;
        while(left<=m-n){
            unordered_map<char,int> temp=freq;
            for(int i=left;i<=right;i++){
                if(temp.find(s2[i])!=temp.end() && temp[s2[i]]>0){
                    temp[s2[i]]--;
                }else{
                    break;
                }
            }
                if(allZero(temp)){
                    return true;
                }
                left++;
                right++;
            
        }
      

    return false;

    }
};
