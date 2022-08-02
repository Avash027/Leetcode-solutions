constexpr int MOD = 1e9+7;

class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        vector<long long> dp(3 , 0);
        
        for(int e:nums){
            
            if(e == 0){
                dp[0] = dp[0] + //We dont take current element
                        dp[0] + //We add current element to previous list
                        1; //We only take this zero
                dp[0]%=MOD;
            }
            if(e == 1){
                dp[1] = dp[1] + // We add it to list of 1
                        dp[0] +  // We add it to list of 0
                        dp[1]; // Dont add 1 and take the previous list
                dp[1]%=MOD;
            }
            if(e == 2){
                dp[2] = dp[2] + 
                        dp[1] + 
                        dp[2];
                dp[2]%=MOD;
            }
            
        }
        
        return (int)dp[2];
    }
};