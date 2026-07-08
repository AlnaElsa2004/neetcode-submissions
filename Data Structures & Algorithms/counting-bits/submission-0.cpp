class Solution {
public:

int hammingWeight(uint32_t n) {
       int count=0;
       while(n>0){
        if(n&1)
        count++;
        n=n>>1;
       }
       return count;
    }

    vector<int> countBits(int n) {
      vector<int> res;
      for(int i=0;i<=n;i++){
        res.push_back(hammingWeight(i));
      }  
      return res;
    }
};
