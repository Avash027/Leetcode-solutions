class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp(n , 1);
        vector<int> par(n , -1);
        
        sort(begin(nums),end(nums));
        
        int mx = -1 , mx_ind = 0;
        
        
        for(int i = 1;i<n;i++)
            for(int j = i-1;j>=0;j--)
                if(nums[i]%nums[j] == 0)
                    if(dp[j]+1>dp[i]){
                        dp[i] = dp[j]+1;
                        par[i] = j;
                        
                        if(mx < dp[i]) mx = dp[i] , mx_ind = i;
                    }
        
        vector<int> ans;
        
        while(mx_ind!=-1){
            ans.push_back(nums[mx_ind]);
            mx_ind = par[mx_ind];
        }
        
        reverse(begin(ans),end(ans));
        
        return ans;
        
        
    }
};