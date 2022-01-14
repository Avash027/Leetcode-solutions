class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin() , nums.end() , 0);
        
        if(sum&1) return false;
        
        const int N = nums.size();
        const int M = sum/2;
        
        vector<vector<int>> dp(N+1,vector<int>(M+1,0));
        
        for(int i = 0;i <=N;i++) dp[i][0] =1;
        for(int  i = 0;i<=M;i++) dp[0][i] = 0;
        
        
        for(int i = 1;i<=N;i++)
            for(int j = 1;j<=M;j++)// j is the sum
            {
                dp[i][j] = dp[i-1][j];
                if(j>=nums[i-1]) dp[i][j] |= dp[i-1][j - nums[i-1]];
            }
        

        
        return dp[N][M];
        
        
    }
};