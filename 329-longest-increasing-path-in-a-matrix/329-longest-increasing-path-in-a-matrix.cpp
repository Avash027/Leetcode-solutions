const int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

class Solution {
private:
    vector<vector<int>> dp;
    vector<vector<int>> mat;
    
    int n,m;
    int dfs(int x , int y){
        if(dp[x][y]!=-1) return dp[x][y];
        
        int mx =1;
        
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx< n and nx>=0 and ny< m and ny>=0
              and mat[nx][ny]> mat[x][y]){
                mx = max(mx , dfs(nx,ny)+1);
            }
        }
        
        return dp[x][y] = mx;
    
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
         
        n = matrix.size();
        m = matrix[0].size();
        
        dp.assign(n , vector<int>(m, -1));
        mat = matrix;
        
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                if(dp[i][j]==-1) dfs(i,j);
        
        int ans = 0;
        
        for(int i = 0;i<n;i++)
            for(int j  =0;j<m;j++) ans= max(ans , dp[i][j]);
        
        return ans;
        
        
    }
};