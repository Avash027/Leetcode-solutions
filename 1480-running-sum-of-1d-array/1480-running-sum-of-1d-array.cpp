class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sum(nums.size() , 0);
        
        for(int i = 0;i<nums.size();i++)
            sum[i] = nums[i] + (i == 0?0:sum[i-1]);
        
        return sum;
    }
};