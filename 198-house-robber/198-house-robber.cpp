class Solution {
private:
    
    int maxAns(vector<int>& nums,int i,vector<int>&dp){
        if(i <= 0) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        return dp[i] =  max(nums[i-1] + maxAns(nums,i-2,dp) , maxAns(nums,i-1,dp));
    }
    
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1 , -1);
        dp[0] = 0;
        dp[1] = nums[0];
        
        for(int i =2;i<=nums.size();i++)
            dp[i] = max(nums[i-1] + dp[i-2] , dp[i-1]);
        
        return dp.back();
        
    }
};