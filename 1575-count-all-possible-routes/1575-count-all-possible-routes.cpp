constexpr int MOD = 1e9+7;

class Solution {
private:
    
    static const int N = 201;
    int dp[N][N];

    
    int totalCost(int v , vector<int>&locations,int fuel,int finish){
       int ways = 0;
        
        if(v == finish)
            ways++;
        
   
        if(dp[v][fuel]!=-1)
            return dp[v][fuel];
        
        
        
        
        for(int i = 0;i<locations.size();i++){
            int cost = abs(locations[v] - locations[i]);
            
            if(cost>fuel or i == v)
                continue;
            
            ways += totalCost(i,locations,fuel-cost,finish);
            ways%=MOD;
        }
        

        
        return dp[v][fuel] = ways;

 
        
    }
    
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp,-1,sizeof(dp));

        
        return totalCost(start,locations,fuel,finish);
    }
};