class Solution {
public:
    int maxProfit(vector<int>& prices) {
     
        const int n = prices.size();
        vector<vector<int>> dp(n+2 , vector<int>(2 , 0));
        
        //0- buy and 1- sell
        for(int i = n-1;i>=0;i--){
            dp[i][0] = max(dp[i+1][0] , -prices[i] + dp[i+1][1]);
            dp[i][1] = max(dp[i+1][1] , prices[i] + dp[i+2][0]);
        }
        
        return dp[0][0];
    }
};