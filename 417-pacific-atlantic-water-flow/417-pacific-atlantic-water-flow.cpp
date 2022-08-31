constexpr int dx[4] = {1,0,-1,0};
constexpr int dy[4] = {0,1,0,-1};

class Solution {
private:
    void dfs(vector<vector<int>>& mat , vector<vector<bool>>& vis,int x,int y){
        
        int n = mat.size();
        int m = mat[0].size();
        
        vis[x][y] = true;
        
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 or nx>=n or ny<0 or ny>=m or vis[nx][ny] or mat[nx][ny]<mat[x][y])
                continue;
            
            dfs(mat,vis,x+dx[i],y+dy[i]);
        }
        
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        const int n = h.size();
        const int m = h[0].size();
        
        vector<vector<bool>> a(n , vector<bool>(m,false));
        vector<vector<bool>> b(n , vector<bool>(m,false));
        
        for(int i = 0;i<n;i++){
            dfs(h,a,i,0);
            dfs(h,b,i,m-1);
        }
        
        for(int i = 0;i<m;i++){
            dfs(h,a,0,i);
            dfs(h,b,n-1,i);
        }
        
        vector<vector<int>> ans;
        
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                if(a[i][j] and b[i][j])
                    ans.push_back({i,j});
        
        return ans;
        
    }
};