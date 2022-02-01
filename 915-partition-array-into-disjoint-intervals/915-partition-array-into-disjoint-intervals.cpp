class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        const int n = nums.size();
     
        int pre = nums[0];
        int ans = 1;
        int gmax = nums[0];
        
        
        
        for(int i =1;i<n-1;i++){
           if(pre>nums[i]) ans = i+1 , pre = gmax;
            else gmax = max(gmax , nums[i]);
        }
        
        return ans;
    }
};