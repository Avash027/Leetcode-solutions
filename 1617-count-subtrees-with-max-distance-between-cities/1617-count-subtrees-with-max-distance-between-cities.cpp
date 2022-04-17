class Solution {
private:
    vector<vector<int>> adj;
    int d;

    int dfs(int v , int p , int& code){
        code -= (1<<v);
        
        int l = 0 , r = 0;
        
        for(auto e:adj[v]){
            if(e == p) continue;
            if((code&(1<<e)) == 0) continue;
            
            int cur =  dfs(e , v , code)+1;
            
            if(cur>l)
                r = l , l = cur;
            else if(cur>r)
                r  =cur;
        }
        
        d = max(d , l+r);
        return l;
    }
    
    void init(int n , vector<vector<int>>& edges){
        adj.resize(n+1);
        
        for(auto&e:edges){
            adj[e[0]-1].push_back(e[1]-1);
            adj[e[1]-1].push_back(e[0]-1);
        }
        
        
    }
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        init(n , edges);
        int code = (1<<(n))-1;
        vector<int> ans(n-1 , 0);
        
        for (int s=code; s; s=(s-1)&code){
            if(((s-1)&s) == 0) continue;
            
            int c = s;
            d = 0;
            int src = -1;
            
            for(int i = 0;i<30;i++){
                if((1<<i)&(c)){
                    src = i;
                    break;
                }
            }
            
            dfs(src , -1 , c);
           
            if(c == 0) ans[d-1]++;
        }

        //     int c = 13;
        // dfs(0 , -1,c , 0);
        
        
     
        
        return ans;
        
    }
};