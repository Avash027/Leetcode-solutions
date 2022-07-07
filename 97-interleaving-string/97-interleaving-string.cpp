class Solution {
private:
    static const int N = 201;
    int dp[N][N];
    
    
    
    int find(string&s1 , string&s2,string&s3,int i=0,int j=0,int k=0){
      
        if(k == s3.size())
            return i == s1.size() and j == s2.size();

        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int possible = 0;
        
        if(i<s1.size() and s1[i] == s3[k])
            possible |= find(s1,s2,s3,i+1,j,k+1);
        if(j<s2.size() and s2[j] == s3[k])
            possible |= find(s1,s2,s3,i,j+1,k+1);
        
        
        return dp[i][j] = possible;
        
    }
    
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        
        return find(s1,s2,s3);
    }
};