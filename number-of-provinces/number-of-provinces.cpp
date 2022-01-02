class Solution {
private:
    vector<bool> vis;
    
    void dfs(int v ,const vector<vector<int>>& arr){
        vis[v] = true;
        
        for(int to = 0;to<arr[v].size();to++){
            if(to!=v and arr[v][to] and !vis[to]) 
                dfs(to,arr);
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& arr) {
    
        vis.assign(arr.size() , false);
        int count = 0;
        
        for(int i = 0;i<arr.size();i++)
            if(!vis[i]) dfs(i,arr) , count++;
        
        return count;
    }
};