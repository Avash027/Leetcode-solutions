class Solution {
private:
    vector<int> vis;
    vector<vector<int>> ans;
    
    void dfs(int v,
             int dest , 
             vector<vector<int>>& graph,
             vector<int>& cur){
        
        cur.push_back(v);
        
        if(v == dest)    
            ans.push_back(cur);
        
        
        vis[v]=1;
        
        for(const int&e:graph[v])
            if(vis[e]!=1)
                dfs(e,dest,graph,cur);
            
        
        
        cur.pop_back();
        vis[v]=2;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vis.assign(20,0);
        vector<int> cur;
        
        dfs(0,(int)graph.size()-1,graph,cur);
        
        return ans;
        
    }
};