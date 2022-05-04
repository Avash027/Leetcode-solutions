class Solution {
private:
    void lis(vector<int>& nums , vector<int>& dp){
        vector<int> a;
        
        const int n = nums.size();
        
        for(int i = 0;i<n;i++){
            if(a.size() == 0 or nums[i] > a.back())
                 dp[i] = a.size(),a.push_back(nums[i]);
            else{
                int index = lower_bound(begin(a),end(a) , nums[i]) - begin(a);
                if(index == a.size()) continue;
                dp[i] = index;
                a[index] = nums[i];
            }
            

        }
        

    }
        
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n) , dp1(n);
        
        lis(nums , dp);
        reverse(begin(nums),end(nums));
        lis(nums,dp1);
        reverse(begin(dp1),end(dp1));
        
        
        int ans = 1e6;
        
        for(int i = 1;i<n-1;i++)
           if(dp[i] and dp1[i])
            ans = min(ans, n - (dp[i] + dp1[i] +1));
        
        return ans;
    }
};