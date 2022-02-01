class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        const int n = nums.size();
        int suf[n];
        int pre = -1;
        
        suf[n-1] = nums[n-1];
        
        for(int i = n-2;i>=0;i--)
            suf[i] = min(nums[i] , suf[i+1]);
        
        for(int i =0;i<n-1;i++){
            pre = max(pre , nums[i]);
            if(pre<=suf[i+1]) return i+1;
        }
        
        return n;
    }
};