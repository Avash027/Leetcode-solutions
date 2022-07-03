class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        const int N = nums.size();
        
        vector<vector<int>> dp(N , vector<int>(2,1));
        
        
        for(int i = 1;i<N;i++)
            for(int j = i-1;j>=0;j--){
                if(nums[i] - nums[j]<0)
                    dp[i][0] = max(dp[i][0] , dp[j][1]+1);
                else if(nums[i] - nums[j] > 0)
                    dp[i][1] = max(dp[i][1] , dp[j][0]+1);
            }
        
        return max(dp[N-1][0] , dp[N-1][1]);
        
        
    }
};