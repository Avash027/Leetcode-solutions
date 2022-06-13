struct DSU{
    
    vector<int> par;
    vector<int> rank;
    
    DSU(int n){
        par.resize(n);
        iota(begin(par),end(par) , 0);
        rank.assign(n , 1);
    }
    
    inline int findPar(int u){
        if(par[u] == u) return u;
        return par[u] = findPar(par[u]);
    }
    
    void merge(int u , int v){
        u = findPar(u);
        v = findPar(v);
        
        if(v == u) return;
        
        if(rank[u]<rank[v]) swap(u,v);
        
        rank[u]+=rank[v];
        par[v] = u;
    }
    
    inline bool sameComp(int u , int v){
        return findPar(u) == findPar(v);
    }
    
    int numOfNodes(int u){
        u = findPar(u);
        return rank[u];
    }
    
};

bool comp(vector<int>&a , vector<int>&b){
    return a[0]>b[0];
}


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n+1) , bob(n+1);
        int ans = 0;
        
        sort(begin(edges),end(edges) , comp);
        
        for(auto e:edges){
            int type = e[0];
            int u = e[1];
            int v = e[2];
            
            
            if(type == 3){
                if(alice.sameComp(u,v)) ans++;
                else{
                    alice.merge(u,v);
                    bob.merge(u,v);
                }
            }
            else if(type == 2){
                if(bob.sameComp(u,v)) ans++;
                else bob.merge(u,v);
            }
            else{
                if(alice.sameComp(u,v)) ans++;
                else alice.merge(u,v);
            }
            
        }
        
  
        
        if(alice.numOfNodes(1)<n or bob.numOfNodes(1)<n)
            return -1;
        
        return ans;
    }
};