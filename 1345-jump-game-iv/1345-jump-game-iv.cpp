constexpr int INF = 1e9;
class Solution {
private:
    map<int,vector<int>> idx;
    
  
    
    int bfs(vector<int>&arr ,  int n){
        int dis[n];
        fill(dis , dis+n , INF);
        queue<int> q;
        
        q.push(0);
        dis[0] = 0;
        
        while(!q.empty()){
            int v = q.front();
            q.pop();
            if(v-1>=0) idx[arr[v]].push_back(v-1);
            if(v+1<n) idx[arr[v]].push_back(v+1);
            
            for(auto&e:idx[arr[v]])
                if(dis[e]==INF){
                    dis[e] = dis[v]+1;
                    q.push(e);
                }
            
            idx[arr[v]].clear();
        }
        
    
        
        return dis[n-1];
    }
    
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
      
        
        for(int i = 0;i<n;i++)
            idx[arr[i]].push_back(i);
        
        
        
        return bfs(arr , n);
    }
};