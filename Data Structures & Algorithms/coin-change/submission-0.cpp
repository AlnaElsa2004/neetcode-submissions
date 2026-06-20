

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       int n=coins.size();
       int x;
        sort(coins.begin(),coins.end());
       vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        if(amount==0){
            return 0;
        }
        if(n==0){
            return -1;
        }

    for(int i=0;i<n;i++){
        dp[i][0]=0;
        for(int j=1;j<=amount;j++){
            if(i==0){
                if(j%coins[0]==0){
                    int y=j/coins[0];
                    dp[0][j]=y;
                    
                }
            }}
    }
    for (int i=1;i<n;i++){
        for(int j=1;j<=amount;j++){           
             if(coins[i]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                 x = j - coins[i];
                    if (dp[i][x] != -1 && dp[i - 1][j] != -1)
                        dp[i][j] = min(dp[i - 1][j], dp[i][x] + 1);
                    else if (dp[i][x] != -1)
                        dp[i][j] = dp[i][x] + 1;
                    else
                        dp[i][j] = dp[i - 1][j];
            }
        }
    }
        
        
    
    return dp[n-1][amount];
    }

};