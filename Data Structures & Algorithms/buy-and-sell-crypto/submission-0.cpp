class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int i=0;
        int n=prices.size();
        while(i<n){
            int buy=prices[i];
            for(int j=i+1;j<n;j++){
                int tot=prices[j]-prices[i];
                maxi=max(maxi,tot);
            }
            i++;
        }
        return maxi;
    }
};
