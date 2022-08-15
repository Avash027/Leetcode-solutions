constexpr int MOD =1e9+7;

class Solution {
private:
    
    int dp[5010][8][17];
    
    int count(int n, vector<int>& rollMax,int clen,int last){
        if(n == 0)
            return 1;
        
        if(dp[n][last][clen] != -1)
            return dp[n][last][clen];
        
        int ans = 0;
        
        for(int i = 0;i<=5;i++){
            if(i+1 == last and clen == rollMax[i]) continue;
            ans += count(n-1,rollMax , (i+1 == last ? clen+1 :1) , i+1);
            ans%=MOD;
        }
        
        return dp[n][last][clen] =  ans;
    }
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp,-1,sizeof(dp));
        return count(n,rollMax,0,0);
    }
};