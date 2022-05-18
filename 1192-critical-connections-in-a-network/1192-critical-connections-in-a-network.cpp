class Solution {
private:
    static const int N = 1e5+1;
    vector<int> graph[N];
    vector<int> vis , in , low;
    int timer = 0;
    vector<vector<int>> ans;
    
    void dfs(int v , int p){
        vis[v] = true;
        in[v] = low[v] = timer++;

        
        for(int to:graph[v]){
            if(to == p)
                continue;
            if(vis[to])
                low[v] = min(low[v] , in[to]);
            else{
                dfs(to,v);
                low[v] = min(low[v] ,low[to]);
                
                if(low[to]>in[v])
                   ans.push_back(vector<int>{to,v});
            }
        }
        
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vis.assign(n+1 , 0);
        in.assign(n+1 , 0);
        low.assign(n+1 , 0);
        
        for(auto&e:connections){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        dfs(connections[0][0],-1);
        
        return ans;
    }
};