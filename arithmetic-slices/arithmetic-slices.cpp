class Solution {
private:
   
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        
        const int N = nums.size();
        vector<int> dp(N , 0);
        
        if(N<=2) return ans;
        
        
        
        for(int i =2;i<N;i++)
        {
            if(nums[i] - nums[i-1] == nums[i-1]-nums[i-2])
                dp[i] = dp[i-1]+1;
            else
                dp[i] = 0;
            
            ans+=dp[i];
        }
        
        return ans;
        
        
    
       
    }
};