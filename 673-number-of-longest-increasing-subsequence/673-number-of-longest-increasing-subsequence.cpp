class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        const int N = nums.size();
        vector<pair<int,int>> dp(N , {1,1});//length,count
        
        for(int i = 0;i<N;i++){
            for(int j = i-1;j>=0;j--){
                
                if(nums[j]>=nums[i]) continue;
                if(dp[j].first+1 == dp[i].first)
                    dp[i].second+=dp[j].second;
                else if(dp[j].first+1>dp[i].first)
                        dp[i] = {dp[j].first+1 , dp[j].second};            
                
            }
        }
        
        int ans = 0 , mx = 0;
        
        for(auto&e:dp){
            
            if(e.first>mx) mx = e.first , ans = e.second;
            else if(e.first==mx) ans+=e.second;
        }
        
        return ans;
    }
};