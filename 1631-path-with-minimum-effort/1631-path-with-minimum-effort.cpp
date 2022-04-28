constexpr int INF = 1e8;
const int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

class Solution {
private:
    int n,m;
    vector<vector<int>> h;
    
    
    void dfs(int x,  int y ,int mx, vector<vector<int>>& vis){
        vis[x][y] = 1;
        
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            
            if(nx<0 or nx>=n or ny<0 or ny>=m or vis[nx][ny])
                continue;
            
            int wt = abs(h[x][y] - h[nx][ny]);
            if(wt > mx) continue;
            
            dfs(nx,ny ,mx, vis);
        }
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
            
        h = heights;
        n = heights.size();
        m = heights[0].size();
        
        int lo = 0 , hi = 1e6+2;
        int ans = -1;
        
        while(lo<=hi){
            int mid = lo + (hi - lo)/2;
            
            vector<vector<int>> vis(n , vector<int>(m , 0));
            
            dfs(0,0,mid,vis);
            
            if(vis[n-1][m-1])
                ans = mid , hi = mid-1;
            else lo = mid+1;
            
        }
        
     return ans;
        
    }
};