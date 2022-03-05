class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> ump;
        vector<int> dp(10001 , 0);
        
        for(const int&e:nums) ump[e]++;
        
        
        for(int i = 1;i<=10000;i++)
        {
            dp[i] = max(dp[i-1] , i*ump[i] + (i>=2?dp[i-2]:0));
        }
        
        return *max_element(dp.begin() , dp.end());
    }
};