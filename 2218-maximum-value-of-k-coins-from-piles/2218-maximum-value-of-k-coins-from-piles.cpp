class Solution {
private:
    int dp[1001][2001];
    
    int maxCoins(int i, vector<vector<int>>& piles , int k){
        if(k == 0 or i >= piles.size())
            return 0;
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        int ans = 0;
        int sum = 0;
        
        ans = max(ans , maxCoins(i+1,piles,k));
        
        for(int j = 0;j<piles[i].size();j++){
            sum+=piles[i][j];
            
            if(k - (j+1) >=0)
                ans = max(ans , sum +  maxCoins(i+1,piles,k-(j+1)));
        
        }
        
        return dp[i][k] = ans;
        
       


    }
    
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        return maxCoins(0,piles,k);
    }
};