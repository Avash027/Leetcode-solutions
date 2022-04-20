class Solution {
private:
    int n , m;
    vector<vector<pair<int,int>>> graph;
    vector<int> d;
    
    inline int node(int x, int y){
        return x*100 + y;
    }
    
    inline void addEdge(int a , int b,int wt){
        graph[a].push_back({b, wt});
    }
    
    void makeGraph(vector<vector<int>>&grid){
      for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++){
              if(j+1<m)
                  addEdge(node(i,j) , node(i,j+1) , grid[i][j]!=1);
              if(j-1>=0)
                  addEdge(node(i,j) , node(i,j-1) , grid[i][j]!=2);
              if(i+1<n)
                  addEdge(node(i,j) , node(i+1,j) , grid[i][j]!=3);
              if(i-1>=0)
                  addEdge(node(i,j) , node(i-1,j) , grid[i][j]!=4);
        }  
    }
    
    void bfs(){
        d[node(0,0)] = 0;
        deque<int> dq;
        dq.push_back(node(0,0));
        
        while(!dq.empty()){
            int v = dq.front();
            dq.pop_front();
            
            for(auto edge:graph[v]){
                int u = edge.first;
                int w = edge.second;
                
                if(d[v] + w >= d[u]) continue;
                d[u] = d[v]+w;
                
                if (w == 1)
                    dq.push_back(u);
                else
                    dq.push_front(u);
            }
        }
    }
public:
    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m  =grid[0].size();
        
        graph.resize(100*(n+m));
        d.assign(100*(n+m) , INT_MAX);
        
        makeGraph(grid);
        bfs();
        
        return d[node(n-1,m-1)];
        
        
    }
};