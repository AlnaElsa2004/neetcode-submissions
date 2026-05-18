class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n=nums.size();
      vector<int> pre(n);
      vector<int> suf(n);
      
      int pref=1;
      pre[0]=1;
      for(int i=1;i<n;i++){
        pref*=nums[i-1];
        pre[i]=pref;
      }
      int su=1;
      suf[n-1]=1;
      for(int i=n-2;i>=0;i--){
         su*=nums[i+1];
         suf[i]=su;
      }
      vector<int> res(n);
      for(int i=0;i<n;i++){
        res[i]=pre[i]*suf[i];
      }
      return res;
    }
};
