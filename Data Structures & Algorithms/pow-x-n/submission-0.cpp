class Solution {
public:
    double myPow(double x, int n) {
       double res=1;
       if(n>0){
       for(int i=0;i<n;i++){
        res*=x;
       }}else{
        double temp = 1.0 / x;
        for(int i=0;i<abs(n);i++){
            res*=temp;
        }
       } 
       return res;
    }
};
