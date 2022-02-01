class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        const int n = nums.size();
        int i = 0 , pre = nums[0] , ans = 0;
        vector<int> suf(n , 1e6);
        
        
        suf[n-1] = nums[n-1];
        
        for(int i = n-2;i>=0;i--)
            suf[i] = min(nums[i] , suf[i+1]);
        
        
        for(int i =1;i<=n-2;i++){
            if(nums[i]>pre and nums[i]<suf[i+1]) ans+=2;
            else if(nums[i]>nums[i-1] and nums[i]<nums[i+1]) ans++;
            
            pre = max(pre , nums[i]);
        }
        
        return ans;
        
    }
};