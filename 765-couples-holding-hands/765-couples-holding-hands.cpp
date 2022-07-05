class Solution {
public:
    
    static const int N = 101;
    vector<int> graph[N];
    bool vis[N];
    
    int dfs(int v){
        vis[v] = true;
        
        int cnt = 1;
        
        for(int e:graph[v])
            if(!vis[e])
                cnt+=dfs(e);
        
        return cnt;
        
    }
    
    int minSwapsCouples(vector<int>& row) {
        
        int pos[row.size()];
        const int n = row.size();
         
        for(int i = 0;i<row.size();i++){
            pos[row[i]] = i/2;
        }
        
        for(int i = 0;i<n;i+=2){
            graph[pos[i]].push_back(pos[i+1]);
            graph[pos[i+1]].push_back(pos[i]);
        }
        
        int ans = 0;
        
        for(int i = 0;i<n;i++)
            if(!vis[i])
                ans+=dfs(i)-1;
        
        return ans;
        
    }
};