constexpr int dx[4] = {1,0,-1,0};
constexpr int dy[4] = {0,1,0,-1};

class Solution {
private:
    bool check(int x,int y, vector<vector<int>>& grid, int n, int mx,vector<vector<int>>& vis){
        vis[x][y] = true;
        
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(!(nx>=0 and nx<n and ny>=0 and ny<n and !vis[nx][ny] and grid[nx][ny]<=mx))
                continue;
            
            if(check(nx,ny,grid,n,mx,vis))
                return true;
        }
        
        
        
        return x==n-1 and y == n-1;
        
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();
        
        int lo = grid[0][0] , hi = n*n;
        int ans= 2 ;
        
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            
            vector<vector<int>> vis(n+1 , vector<int>(n+1,0));
            
            if(check(0,0,grid,n,mid,vis))
                ans = mid, hi = mid-1;
            else lo = mid+1;
            
        }
        

        
        return ans;
    }
};