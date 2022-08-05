constexpr int dx[4] = {1,0,-1,0};
constexpr int dy[4] = {0,1,0,-1};


class Solution {
private:
    bool isPossible(int r, int c, int lastDay,vector<vector<int>>&cells){
        vector<vector<bool>> graph(r,vector<bool>(c,1));
        
        for(int i = 0;i<=lastDay;i++)
            graph[cells[i][0]-1][cells[i][1]-1] = 0;
        
        
        queue<pair<int,int>> q;
        
        for(int i = 0;i<c;i++) if(graph[0][i]) q.push({0,i}) , graph[0][i] = 0;
        

        while(!q.empty()){
            auto [x,y] = q.front();
            
            
            q.pop();
            
            if(x == r-1)
                return true;
            
            for(int i = 0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx>=0 and nx<r and ny>=0 and ny<c and graph[nx][ny])
                        q.push({nx,ny}),graph[nx][ny] = 0;;
                
            }
        }
        
        return false;
        
        
        
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int lo = 0 , hi = cells.size()-1;
        int ans = 0;
        
        while(lo<=hi){
            int mid = (lo+hi)/2;
            
            if(isPossible(row,col,mid,cells))
                ans= mid+1 , lo = mid+1;
            else 
                hi = mid-1;
        }
        
       
        
        return ans;
    }
};