constexpr int dx[4] = {1,0,-1,0};
constexpr int dy[4] = {0,1,0,-1};


class Solution {

private:
    
int dfs(int x,int y , vector<vector<int>>& grid){

    
    grid[x][y] = 0;
    int count = 1;
    
    for(int i = 0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx<0 || nx>= grid.size() || ny<0 || ny >= grid[0].size())
            continue;
        
        if(!grid[nx][ny])
            continue;
        
        count+=dfs(nx,ny,grid);
    }
    
    return count;
    
}
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        
        for(int i = 0;i<grid.size();i++)
            for(int j = 0;j<grid[0].size();j++)
                if(grid[i][j])
                    ans = max(dfs(i,j,grid),ans);
        
        return ans;
    }
};