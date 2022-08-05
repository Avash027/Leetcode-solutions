class Solution {

    static const int N = 1001;
    int dp[N];
    
public:
    
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        if(target<0)
            return 0;
        
        if(target == 0){
            return 1;
        }
        
        if(dp[target]!=-1)
            return dp[target];
        
        
        int ans = 0;
        
        for(int e:nums)
            ans += combinationSum4(nums,target - e);
        
        return dp[target] = ans;
    }
};