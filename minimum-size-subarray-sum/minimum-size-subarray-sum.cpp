class Solution {
public:    
    int minSubArrayLen(int target, vector<int>& nums) {
       
        const int N = nums.size();
        int lo = 0 , hi = 0;
        int sum = 0,ans = 100010;
        
        while(hi<N)
        {
            sum+=nums[hi++];
            
            while(lo<hi and sum>=target){
                ans = min(ans , hi-lo);
                sum-=nums[lo++];
            }
        }
        
        if(ans == 100010) ans = 0;
        return ans;
        
    }
};