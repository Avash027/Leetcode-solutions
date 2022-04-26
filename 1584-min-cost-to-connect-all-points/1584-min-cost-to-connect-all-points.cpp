struct DSU{
  vector<int> par, rank;
    
    DSU(){
        par.resize(1000);
        rank.resize(1000);
        iota(begin(par),end(par),0);
        fill(begin(rank),end(rank) , 1);
    }
    
    int find(int u){
        if(par[u] == u) return u;
        return par[u] = find(par[u]);
    }
    
    bool same(int u , int v){
        return find(u) == find(v);
    }
    
    void merge(int u , int v){
        u = find(u);
        v = find(v);
        
        if(u == v) return;
        
        if (rank[u] > rank[v]){
			par[v] = u;
			rank[u] += rank[v];
		}
        
		else{
			par[u] = v;
			rank[v] += rank[u];
		}

    }
};

struct Node{
    int u,v,w;
    
    Node(int x,int y , int k){
        u = x;
        v = y;
        w = k;
    }
};

bool operator < (const Node&a , const Node& b){
    return a.w < b.w;
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        map<vector<int>,int> pti;
        int cnt = 0;
        
        for(auto& e:points)
            pti[e] = cnt++;
        
        vector<Node> arr;
        
        for(int i = 0;i<points.size();i++)
            for(int j = i+1;j<points.size();j++){
                int w = abs(points[i][0] - points[j][0])
                    + abs(points[i][1] - points[j][1]);
                
                Node temp(pti[points[i]] , pti[points[j]] , w);
                
                arr.push_back(temp);
            }
        
        sort(begin(arr),end(arr));
        
        DSU d;
        
        int ans = 0;
        
        for(int i = 0;i<arr.size();i++){
            if(d.same(arr[i].u , arr[i].v)) continue;
            ans+=arr[i].w;
            
            d.merge(arr[i].u , arr[i].v);
        }
        
        return ans;
        
    }
};