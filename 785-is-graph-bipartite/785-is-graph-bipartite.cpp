class Solution {
private:
    static const int N = 101;
    bool vis[N] , col[N];
    
    bool dfs(int v,int c , vector<vector<int>>& graph){
        vis[v] = true;
        col[v] = c;
        
        for(int e:graph[v]){
            if(!vis[e]) if(dfs(e,c^1,graph) == false) return false;
            if(vis[e] and col[v] == col[e]) return false;
            
        }
        
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        bool ans = true;
        
        for(int i = 0;i<graph.size();i++)
            if(!vis[i])
                ans&= dfs(i,0,graph);
        
        return ans;
    }
};