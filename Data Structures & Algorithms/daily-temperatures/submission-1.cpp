class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> out(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(temperatures[i]<temperatures[j]){
                  out[i]=j-i;
                  break;
                }else{
                    out[i]=0;
                    continue;
                }
            }
        }
        return out;
    }
};
