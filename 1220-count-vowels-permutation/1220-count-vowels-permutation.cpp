constexpr int MOD = 1e9+7;


class Solution {
public:
    
  
    
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n+1 , vector<int>(5 , 0));
        
        for(int i = 0;i<5;i++)
            dp[1][i] = 1;
        
        for(int i =1 ;i<n;i++){
            (dp[i+1][1]+=dp[i][0])%=MOD;
            
            (dp[i+1][0]+=dp[i][1])%=MOD;
            (dp[i+1][2]+=dp[i][1])%=MOD;
            
            for(int j = 0;j<=4;j++)
                if(j != 2)
                    (dp[i+1][j]+=dp[i][2])%=MOD;
            
            (dp[i+1][2]+=dp[i][3])%=MOD;
            (dp[i+1][4]+=dp[i][3])%=MOD;
            
            (dp[i+1][0]+=dp[i][4])%=MOD;
        }
        
        int ans = 0;
        
        for(int i = 0;i<5;i++)
            (ans+=dp[n][i])%=MOD;
        
        return ans;
    }
};