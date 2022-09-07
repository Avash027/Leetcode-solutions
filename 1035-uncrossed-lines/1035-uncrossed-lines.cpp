class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        const int N = nums1.size();
        const int M = nums2.size();
        
        int dp[N+1][M+1];
        memset(dp,0,sizeof(dp));   
        
        for(int i = 1;i<=N;i++)
            for(int j = 1;j<=M;j++){
                if(nums1[i-1] == nums2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        
        return dp[N][M];
        
        
    }
};