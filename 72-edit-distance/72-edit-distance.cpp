class Solution {
    
private:
    
    vector<vector<int>> dp;
    
//     int minDistance(string s1, string s2, int i, int j){
//         if(i == 0 and j == 0)
//             return 0;
//         else if(i == 0 and j!=0)
//             return j;
//         else if(i!=0 and j==0)
//             return i;
        
//         if(dp[i][j]!=-1)
//             return dp[i][j];
        
        
        
//         if(s1[i-1] == s2[j-1])
//             return dp[i][j] =  minDistance(s1,s2,i-1,j-1);
        
        
//         return dp[i][j] = 1+min({
//             minDistance(s1,s2,i-1,j),
//             minDistance(s1,s2,i,j-1),
//             minDistance(s1,s2,i-1,j-1)
//             });
        
//     }
public:
    int minDistance(string word1, string word2) {
        
        const int n = word1.size() , m = word2.size();
        
        dp.assign(n+1 , vector<int>(m+1 , 0));
        
        for(int i =1;i<=n;i++)
            dp[i][0] = i;
        
        for(int i = 1;i<=m;i++)
            dp[0][i] = i;
        
        for(int i = 1;i<=n;i++)
            for(int j = 1;j<=m;j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1+min({dp[i-1][j] , dp[i][j-1], dp[i-1][j-1]});
            }
        
        return dp[n][m];
        
        // return minDistance(word1,word2,word1.size() , word2.size());
    }
};