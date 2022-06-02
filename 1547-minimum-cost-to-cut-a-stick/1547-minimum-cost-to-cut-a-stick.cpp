class Solution {
private:
    
    vector<vector<int>> dp;
    
    int costCalc(vector<int>&cost , int lb , int rb){
        if(abs(rb - lb)<=1) return 0;
        
        if(dp[lb][rb]!=-1) return dp[lb][rb];
        
        int ans = 1e9;
        
        for(int i = lb+1;i<rb;i++)
            ans = min(ans , costCalc(cost,lb,i) + costCalc(cost,i,rb) + cost[rb] - cost[lb]);
        
        return dp[lb][rb] = ans;
    }
    
public:
    int minCost(int n, vector<int>& cuts) {
        dp.assign(105 , vector<int>(105 , -1));
        
        cuts.push_back(n);
        cuts.insert(cuts.begin() , 0);
        sort(begin(cuts),end(cuts));
    
        int N = cuts.size();
        
        return costCalc(cuts,0,N-1);
    }
};