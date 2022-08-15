constexpr int MOD =1e9+7;

class Solution {
// private:
    
//     int dp[5010][8][17];
    
//     int count(int n, vector<int>& rollMax,int clen,int last){
//         if(n == 0)
//             return 1;
        
//         if(dp[n][last][clen] != -1)
//             return dp[n][last][clen];
        
//         int ans = 0;
        
//         for(int i = 0;i<=5;i++){
//             if(i+1 == last and clen == rollMax[i]) continue;
//             ans += count(n-1,rollMax , (i+1 == last ? clen+1 :1) , i+1);
//             ans%=MOD;
//         }
        
//         return dp[n][last][clen] =  ans;
//     }
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        int dp[n+1][7][16];
        
        memset(dp,0,sizeof(dp));
        
        
        for(int i = 1;i<=6;i++)
            dp[1][i][1] = 1;
        
        
        for(int i = 2;i<=n;i++){
            for(int j = 1;j<=6;j++) // current
                for(int k = 1;k<=6;k++) // prev
                    for(int l = 1;l<=15;l++){
                        if(j == k and l+1<=rollMax[j-1])
                            (dp[i][j][l+1]+= dp[i-1][j][l])%=MOD;
                        else if(j!=k)
                            (dp[i][j][1] += dp[i-1][k][l])%=MOD;
                            
                    }
            }
        
        int ans = 0;
        
        for(int i = 1;i<=6;i++)
            for(int l = 1;l<=15;l++)
                (ans+=dp[n][i][l])%=MOD;
        
        return ans;
    }
};