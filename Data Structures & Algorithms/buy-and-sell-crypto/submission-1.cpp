class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int n=prices.size();
       int minprice=prices[0];
       for(int i=1;i<n;i++){
        minprice=min(minprice,prices[i-1]);
        int profit=prices[i]-minprice;
        maxi=max(maxi,profit);
       }
       return maxi;
    }
};
