class Solution {
public:
   int helper(int n){
    int sum=0;
    while(n>0){
        int r=n%10;
        n=n/10;
        sum+=r*r;
    }
    return sum;
   }
    bool isHappy(int n) {
        unordered_set<int>s;
        while(n!=1){
            if(s.find(n)!=s.end()){
                return false;
            }
            s.insert(n);
            n=helper(n);
        }
        return true;
    }
};
