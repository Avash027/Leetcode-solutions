class Solution {
private:
    
    int numOfWays(int n,vector<int>&dp){
        if(n == 0 or n == 1)
            return 1;
        
        return dp[n] = (dp[n]==-1?numOfWays(n-1,dp) + numOfWays(n-2,dp):dp[n]);
    }
    
public:
    int climbStairs(int n) {
        vector<int> dp(n+1 , -1);
        return numOfWays(n,dp);
    }
};