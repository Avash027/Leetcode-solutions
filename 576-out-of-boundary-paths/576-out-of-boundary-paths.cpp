constexpr int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
constexpr int MOD = 1e9+7;

class Solution {
private:
    vector<vector<vector<int>>> dp;
    vector<vector<int>> vis;
    int n,m;
    
    int dfs(int x, int y , int moves){
        if(moves < 0)
            return 0;
        if(x<0 or x>=n or y<0 or y>=m)
            return 1;
        
        vis[x][y]=1;
        
        if(dp[x][y][moves]!=-1)
            return dp[x][y][moves];
        
        int ans = 0;
        
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            
            ans = (ans%MOD + dfs(nx,ny,moves-1)%MOD)%MOD;
        }
        
        return dp[x][y][moves] = ans;
        
    }
    
public:
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        vis.assign(51 , vector<int>(51 , 0));
        dp.assign(51 , vector<vector<int>>(51 , vector<int>(51 , -1)));
    
        this->n = n;
        this->m = m;
        
        return dfs(startRow,startColumn,maxMove);
    
    }
};