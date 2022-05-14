
    static const int INF = 10000000;
class Solution {
private:
    static const int N = 1000;
    
    vector<pair<int,int>> adj[N];
    vector<int> dis;
    
    void dijkstra(int src) {

	priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
	pq.push({0, src});
	dis[src] = 0;

	while (!pq.empty())
	{
		int u = pq.top().second;
		int dis_u = pq.top().first;
		pq.pop();
		if (dis[u] != dis_u) continue;
		for (auto e : adj[u])
		{
			int v = e.first;
			int vd = e.second;
			if (dis[v] > dis[u] + vd)
			{
				dis[v] = dis[u] + vd;
				pq.push({dis[v], v});
			}
		}
	}

}

    
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        for(auto&e:times)
            adj[e[0]].push_back({e[1] , e[2]});
        
        dis.assign(N , INF);
        
        dijkstra(k);
        
        int ans = -INF;
        
        for(int i =1;i<=n;i++)
            ans = max(ans , dis[i]);
        
        if(ans == INF)
            ans = -1;
        
        return ans;
    }
};