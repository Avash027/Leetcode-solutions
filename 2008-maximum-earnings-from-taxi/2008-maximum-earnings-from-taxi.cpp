struct Segtree{
  
    static const int N = 1e5;
    const long long INF = 1e15;
    long long t[4*N];
    
    Segtree(){
        memset(t,0,sizeof(t));
    }
    
    long long get(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return -INF;
        if (l == tl && r == tr) {
            return t[v];
        }
        
        int tm = (tl + tr) / 2;
        
        return max(get(v*2, tl, tm, l, min(r, tm))
           , get(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
    
    long long get(int end){
        return get(1,0,N-1,0,end);
    }
    
    void update(int v, int tl, int tr, int pos, long long new_val) {
        if (tl == tr) {
            t[v] = max(new_val,t[v]);
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
              update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = max(t[v*2] , t[v*2+1]);
        }
    }
    
    void update(int pos,long long new_val){
        update(1,0,N-1,pos,new_val);
    }
};

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(begin(rides),end(rides));
        
        long long ans = 0;
        Segtree st;
        
        for(auto&e:rides){
            long long prevMaxRide = st.get(e[0]);
            long long curMaxRide = e[1]-e[0]+e[2] + prevMaxRide;
            ans = max(ans , curMaxRide);
            st.update(e[1],curMaxRide);
        }
        
        return ans;
        
    }
};