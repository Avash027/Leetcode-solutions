class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();
        vector<int> dp(N,1);
        
        
        for(int i = 1;i<N;i++)
            if(ratings[i] > ratings[i-1])
                dp[i] = dp[i-1]+1;
        
        for(int i = N-2;i>=0;i--)
            if(ratings[i] > ratings[i+1])
                dp[i] = max(dp[i] , dp[i+1]+1);
        
        return accumulate(begin(dp),end(dp),0);
        
       
    }
};