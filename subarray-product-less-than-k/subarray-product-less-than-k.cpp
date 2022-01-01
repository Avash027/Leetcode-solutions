class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        const int N = nums.size();
        int prod = 1,ans = 0;
        
        int lo = 0 , hi = 0;
        
        while(hi<N)
        {
            prod*=nums[hi++];
            while(lo<hi and prod>=k) prod/=nums[lo++];
            
            ans+=hi - lo;
        }
        
        return ans;
        
    }
};