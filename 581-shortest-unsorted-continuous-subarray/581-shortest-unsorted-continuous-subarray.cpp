class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const int n = nums.size();
        
        int lo = 0 , hi = n-1;
        int mx = nums[lo++] , mn =nums[hi--];
        int beg = -1 , end = -2;
        
        
        while(lo<n){
            mx = max(mx , nums[lo]);
            mn = min(mn , nums[hi]);
            
            if(nums[lo]< mx) end = lo;
            if(nums[hi]>mn) beg = hi;
            
            lo++;
            hi--;
        }
        
        return end - beg+1;
    }
};