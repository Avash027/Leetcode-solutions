class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        const int N = nums.size();
        vector<int> dp(N);
        

        
        
        dp[0] = nums[0];
        set<pair<int,int>> max_prev;
        max_prev.insert({dp[0] , 0});
        int ans = dp[0];
        
        for(int i = 1;i<N;i++){
            
            if(i-k-1>=0)
                max_prev.erase({dp[i-k-1] , i-k-1});
            
            int mx = max_prev.rbegin()->first;
            int mx_ind = max_prev.rbegin()->second;
            
            dp[i] = max(mx + nums[i],nums[i]);
            ans = max(ans , dp[i]);
            max_prev.insert({dp[i],i});
            
        }
        
        
        return ans;
        
        
        
    }
};