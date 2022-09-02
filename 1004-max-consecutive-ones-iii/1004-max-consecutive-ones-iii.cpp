class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        const int N = nums.size();
        
        int lo = 0 , hi = 0;
        int curFlips = 0;
        int ans = 0;
        
        while(hi<N){
            if(nums[hi++] == 0)
                curFlips++;
            
            while(curFlips>k)
                curFlips -= (nums[lo++] == 0);
            
            ans = max(ans,  hi - lo);
        }
        
        return ans;
    }
};