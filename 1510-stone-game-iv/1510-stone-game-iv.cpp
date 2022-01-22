class Solution {
private:
    inline bool isSquare(int n){
        return ceil(sqrt(n)) == floor(sqrt(n));
    }
public:
    bool winnerSquareGame(int n) {
        bool dp[n+1];
        fill(dp , dp+n+1 , false);
        
        dp[1] = true;
        dp[0] = false;
    
        for(int i =2;i<=n;i++)
            for(int j = 1;j*j<=i;j++){
                dp[i]|=(!dp[i-j*j]);
            }  
        
   
        
        return dp[n];
    }
};