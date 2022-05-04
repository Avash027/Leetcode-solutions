class Solution {
private:
    vector<vector<int>> makeLCS(string s1 , string s2){
        const int n = s1.size() , m = s2.size();
        
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));
        
        dp[0][0] = 1;
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        
        return dp;
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp = makeLCS(str1 , str2);
        string ans;
        
        const int n = str1.size() , m = str2.size();
        
        int i = n , j = m;
        
        while(i>0 and j>0){
            if(str1[i-1] == str2[j-1])
                ans.push_back(str1[i-1]) , i-- , j--;
            
            else if(dp[i-1][j] > dp[i][j-1])
                ans.push_back(str1[i-1]), i--;
            
            else ans.push_back(str2[j-1]),  j--;
        }
        
        while(i>0)
            ans.push_back(str1[i-1]) , i--;
        
        while(j>0)
            ans.push_back(str2[j-1]) , j--;
        
        
        
        reverse(begin(ans),end(ans));
        
        return ans;
    }
};