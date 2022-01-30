class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int n = nums.size();
        k%=n;
        
        if(k == 0) return;
    
        reverse(begin(nums)  ,begin(nums) +n-k);
        reverse(begin(nums) + n-k , end(nums));
        reverse(begin(nums),end(nums));
       
        
        
    }
};