class Solution {
public:
    
    static constexpr int INF = 1e8;
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
       
        vector<vector<vector<int>>> dp(m , vector<vector<int>>(n+1 , vector<int>(target+1 , INF)));
        // dp[i][j][k] = Minimum cost to paint ith house with jth color such that their are k neighbours
        
        if(houses[0] == 0)
            for(int paint = 1;paint<=n;++paint)
                dp[0][paint][1] = cost[0][paint-1];
        else
            dp[0][houses[0]][1] = 0;
        
        
        
        for(int houseNum = 1;houseNum < m;houseNum++){
            
            
            int beg = 1,end = n;
            
            if(houses[houseNum]!=0)
                beg = end = houses[houseNum];
            
            for(int curPaint = beg;curPaint <= end; curPaint++) // Possible paints for current house
                for(int prevPaint = 1;prevPaint <= n;prevPaint++) // Possible paints for previous house
                    for(int t = 1;t<=target;t++){
                        if(dp[houseNum-1][prevPaint][t] == INF) // If prev combination was not possible
                            continue;
                        
                        
                        
                        int numOfNeighbours = t + (prevPaint != curPaint); // If paints are different then increase neighbours
                        int curCost = dp[houseNum-1][prevPaint][t];
                        
                        if(curPaint != houses[houseNum])
                            curCost += cost[houseNum][curPaint-1]; // If paints are different increase cost
                        
                        if(numOfNeighbours > target) // No need
                            continue;
                        
                        dp[houseNum][curPaint][numOfNeighbours] = min(
                            dp[houseNum][curPaint][numOfNeighbours],
                            curCost
                        );
                        
                        
                    }
        }
        
        int ans = INF;
        
        for(int i= 0;i<=n;i++)
            ans = min(ans , dp[m-1][i][target]);
        
        return ans == INF?-1:ans;
        
    }
};