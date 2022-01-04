const int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

class Solution {
private:
    int n,m;
    bool found;
    vector<vector<int>> vis;
    vector<vector<char>> board;
    
    bool valid(int x,int y){
        return x>=0 and x<n and y>=0 and y<m and vis[x][y]!=1;
    }
    
    void backTrack(int x, int y, string s , int ind=0){
        vis[x][y] = true;
        
        if(s[ind] == board[x][y]) ind++;
        else{
            vis[x][y]=2;
            return;
        }
        
        if(ind == s.size()){
            found = true;
            vis[x][y] = 2;
            return;
        }
        
        for(int i = 0;i<4;i++)
            if(valid(x + dx[i],y+dy[i]))
                backTrack(x+dx[i],y+dy[i],s,ind);
        
        vis[x][y]=2;
        
    }
    
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        this->board = board;
        vis.assign(n,vector<int>(m,0));
        
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                backTrack(i,j,word,0);
        
        return found;
    }
};