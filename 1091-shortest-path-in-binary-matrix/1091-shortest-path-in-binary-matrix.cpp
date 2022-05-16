constexpr int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1};

class Solution {
private:
    
    vector<vector<int>> grid;
    vector<vector<int>> dis;
    int n;
    
    inline bool valid(int x,int y) {
        return x>=0 and x<n and y>=0 and y<n and grid[x][y]==0 and dis[x][y]==-1;
    }
    
    void bfs(){
        queue<pair<int,int>> q;
        if(grid[0][0]==0) q.push({0,0}) , dis[0][0]=1;
        
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            
            for(int i = 0;i<8;i++){
                int nx = cur.first+dx[i],ny = cur.second+dy[i];
                if(!valid(nx,ny)) continue;
                dis[nx][ny] = dis[cur.first][cur.second]+1;
                q.push({nx,ny});
            }
        }
        
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        dis.assign(n,vector<int>(n,-1));
        
        bfs();
        

        return dis[n-1][n-1];
    }
};