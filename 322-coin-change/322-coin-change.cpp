constexpr int INF = 1e9;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[amount+1];
        
        for(int i = 0;i<amount+1;i++) dp[i] = (i==0?0:INF);
        
        for(int i =1;i<amount+1;i++)
        {
            for(int j = 0;j<n;j++){
               if(coins[j]<=i) dp[i] = min(dp[i] , dp[i-coins[j]]+1);    
            }
        }
        
        
        
        return dp[amount]==INF?-1:dp[amount];
    }
};