class Solution {
private:
    
    int dp[1<<15][20];
    
    bool valid(int mask , int ind){
        return (mask & (1<<ind));
    }
    
    int helper(vector<int>& nums, int mask, int stepNum){
        if(mask == 0)
            return 0;
        
        int ans = 0;
        
        if(dp[mask][stepNum] != -1)
            return dp[mask][stepNum];
        
        for(int i = 0;i<nums.size();i++)
            for(int j = i+1;j<nums.size();j++){
                if(valid(mask , i) and valid(mask , j))
                    ans = max(ans , stepNum*__gcd(nums[i],nums[j]) + 
                              helper(nums , mask - (1<<i) - (1<<j) , stepNum+1));
            }
        
        return dp[mask][stepNum] = ans;
    
    }
public:
    int maxScore(vector<int>& nums) {
        memset(dp , -1,sizeof(dp));
        int mask = (1<<nums.size()) - 1;
        return helper(nums,mask,1);
    }
};