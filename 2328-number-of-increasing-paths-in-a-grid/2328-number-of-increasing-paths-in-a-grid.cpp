constexpr int MOD = 1e9+7;
constexpr int dx[4] = {1,0,-1,0};
constexpr int dy[4] = {0,1,0,-1};

class Solution {
private:
    
    static const int N = 1001;
    int dp[N][N];
    int n,m;
    
    inline bool isValid(int x,int y){
        return x>=0 and x<n and y>=0 and y<m;
    }
    
    int count(int x,int y,vector<vector<int>>&grid){
        

        
        if(dp[x][y]!=-1)
            return dp[x][y];
        
        
        int paths = 1;
        
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(!isValid(nx,ny))
                continue;
            
            if(grid[nx][ny] <= grid[x][y]) continue;
            
            paths += count(nx,ny,grid);
            paths%=MOD;
            
        }
        
        return dp[x][y] = paths;
        
        
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        this->n = grid.size();
        this->m = grid[0].size();
        
        memset(dp,-1,sizeof(dp));

        
        int ans = 0;
        
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++){

                ans+=count(i,j,grid);
                
                
                ans%=MOD;
            }
        
        return ans;
        
    }
};