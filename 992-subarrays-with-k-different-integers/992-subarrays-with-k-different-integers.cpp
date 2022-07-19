class Solution {
private:
    int helper(vector<int>& nums, int k){
        int N = nums.size();
        
        int l = 0, r = 0;
        vector<int> freq(N+1 , 0);
        int cnt = 0 , ans = 0;
        
        while(r<N){
            cnt+=(freq[nums[r++]]++ == 0);
            
            while(cnt>k) cnt-=(--freq[nums[l++]] == 0);
            
            ans+=(r - l);

        }
        
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return helper(nums,k) - helper(nums,k-1); 
    }
};