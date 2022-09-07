constexpr long long INF = 1e14;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        const int N = nums.size();
        
        vector<vector<long long>> dp(N , vector<long long>(2 , 0));
        
        dp[0][0] = nums[0];
        dp[0][1] = -INF;
        
        
        for(int i = 1;i<N;i++){
            dp[i][0] = max({1LL*nums[i], dp[i-1][1] + nums[i],dp[i-1][0]});
            dp[i][1] = max({dp[i-1][1], -nums[i]+dp[i-1][0]});
        }
        
        return max(dp[N-1][0] , dp[N-1][1]);
        
        
    }
};