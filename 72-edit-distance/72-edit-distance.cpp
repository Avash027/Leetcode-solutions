class Solution {
    
private:
    
    vector<vector<int>> dp;
    
    int minDistance(string s1, string s2, int i, int j){
        if(i == 0 and j == 0)
            return 0;
        else if(i == 0 and j!=0)
            return j;
        else if(i!=0 and j==0)
            return i;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        
        if(s1[i-1] == s2[j-1])
            return dp[i][j] =  minDistance(s1,s2,i-1,j-1);
        
        
        return dp[i][j] = 1+min({
            minDistance(s1,s2,i-1,j),
            minDistance(s1,s2,i,j-1),
            minDistance(s1,s2,i-1,j-1)
            });
        
    }
public:
    int minDistance(string word1, string word2) {
        
        dp.assign(501 , vector<int>(501 , -1));
        
        return minDistance(word1,word2,word1.size() , word2.size());
    }
};