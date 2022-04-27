class Solution {
private:
    static const int MX = 100010;
    vector<int> adj[MX];
    bool vis[MX];
    string s;
    
    void dfs(int v , vector<int>& ind , vector<char>& cr){
        vis[v] = true;
        
        ind.push_back(v);
        cr.push_back(s[v]);
        
        for(int e:adj[v])
            if(!vis[e])
                dfs(e , ind , cr);
        
    }
    
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        for(auto e: pairs){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        this->s = s;
        
        for(int i = 0;i<s.size();i++){
            if(vis[i]) continue;
            vector<int> ind;
            vector<char> cr;
            
            dfs(i , ind , cr);
            
            sort(begin(ind),end(ind));
            sort(begin(cr),end(cr));
            
            for(int j = 0;j<ind.size();j++)
                s[ind[j]] = cr[j];
        }
        
        return s;
        
    }
};