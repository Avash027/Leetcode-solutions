class Solution {
public:
    bool checkPartitioning(string s) {
        const int N = s.size();
        bool dp[N+1][N+1];
        memset(dp,false,sizeof(dp));
        
        
        for(int i = 0;i<N;i++) dp[i][i] = true;
        for(int i = 0;i<N-1;i++) dp[i][i+1]= (s[i] == s[i+1]);
        
        
        for(int len = 3;len<=N;len++)
            for(int i = 0;i<N - len+1;i++){
                int j = i + len-1;
                
                dp[i][j] = dp[i+1][j-1] and (s[i]==s[j]);
                
            }
        
        
        for(int i = 1;i<N;i++)
            for(int j = i+1;j<N;j++){
                if(dp[0][i-1] and dp[i][j-1] and dp[j][N-1])
                    return true;
            }
        
        return false;
        
        
    }
};