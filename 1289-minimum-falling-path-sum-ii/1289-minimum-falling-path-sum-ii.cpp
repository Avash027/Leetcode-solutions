constexpr int INF = 1000000;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        const int n = grid.size();
        
       for(int i = 1;i<n;i++)
            for(int j = 0;j<n;j++){
                int mn = INF;
                
                for(int k = 0;k<n;k++)
                    if(j!=k)
                        mn = min(mn , grid[i-1][k]);
            
            grid[i][j]+=mn;
            }
        
        
        return *min_element(begin(grid.back()) ,end(grid.back()));
    }
};