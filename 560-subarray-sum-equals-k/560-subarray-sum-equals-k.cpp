class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        int ans = 0,sum = 0;
        
        unordered_map<int,int> umpp;
        umpp[0] = 1;
        
        
        for(int i = 0;i<n;i++){
            sum+=nums[i];
            if(umpp.find(sum-k)!=umpp.end())
                ans+=umpp[sum-k];
            
            umpp[sum]++;
        }
        
        
        return ans;
        
        
        
    }
};