class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
  int n0=0, n1 = 0;
        
        for (auto &s : strs) {
          n0 = n1 = 0;
            for (auto c : s) {
                if (c == '0')
	                n0++;
                else
	                n1++;
            }
     
            
            for(int i = m;i>=n0;i--)
                for(int j = n;j>=n1;j--)
                    dp[i][j] = max(dp[i][j], dp[i - n0][j - n1] + 1);
            }
         return dp[m][n];
            
           
 
    }
};