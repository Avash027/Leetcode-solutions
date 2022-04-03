class Solution {
private:
    //top down approach
    int numOfWays(int n,vector<int>&dp){
        if(n == 0 or n == 1)
            return 1;
        
        return dp[n] = (dp[n]==-1?numOfWays(n-1,dp) + numOfWays(n-2,dp):dp[n]);
    }
    
public:
    int climbStairs(int n) {
        int p0 = 1 , p1 = 1,ans =1;
        
        for(int i = 2;i<=n;i++){
            ans = p0 + p1;
            p0=p1;
            p1=ans;
        }
        
        return ans;
    }
};