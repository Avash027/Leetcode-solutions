struct DSU{
  
    vector<int> par;
    vector<int> rank;
    
    DSU(int n){
        rank.assign(n+1 , 0);
        par.resize(n+1);
        
        iota(begin(par),end(par),0);
    }
    
    
    int findPar(int x){
        if(par[x] == x) return x;
        return par[x] = findPar(par[x]);
    }
    
    bool merge(int u , int v,vector<vector<int>>& restr){
        u = findPar(u);
        v = findPar(v);
        
        for(auto&e:restr){
            e[0] = findPar(e[0]);
            e[1] = findPar(e[1]);
            
            if(e[0] == u and e[1] == v)
                return false;
            
            if(e[0] == v and e[1] == u)
                return false;
        }
        
        if(rank[u]<rank[v])
            swap(u,v);
        
        rank[u]+=rank[v];
        par[v] = u;
        
        return true;
        
    }
    
};


class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        
        vector<bool> res;
        
        DSU d(1001);
        
        for(auto&e:requests){
            res.push_back(d.merge(e[0],e[1],restrictions));
        }
        return res;
    }
};