class Solution {
private:
    
    int maxSubarray(vector<int>& nums){
        int localMax = nums[0];
        int globalMax = nums[0];
        
        for(int i = 1;i<nums.size();i++){
            localMax = max(localMax + nums[i] , nums[i]);
            globalMax = max(localMax , globalMax);
        }
        
        return globalMax;
        
    }
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = maxSubarray(nums);
        
        for(int&e:nums) e = -e;
        
        ans = max(ans , maxSubarray(nums));
        
        return ans;
    }
};