class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();
        int k = 1;

        int maxi = *max_element(piles.begin(), piles.end());

        while(k <maxi) {
            int mid=(k+maxi)/2;
            long long sum = 0;

            for(int i = 0; i < n; i++) {
                sum +=(piles[i]+mid-1)/ mid;
            }

            if(sum <= h) {
                maxi=mid;
            }
            else {
                k=mid+1;
            }
        }
     return k;
       
    }
};