class Solution {
public:
    int jump(vector<int>& nums) {
           int n = nums.size();
        constexpr int INF = 1e6;
        
        vector<int> jump(n , INF);
        
        jump[0] =0;
        
        for(int i =0;i<n-1;i++)
        {
            int ind = i+1;
            int val = nums[i];
            
            while(val-- and ind<n) jump[ind] = min(jump[ind] , jump[i]+1) , ind++;
        }
        
        return jump.back();
    }
};