class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> graph;
        unordered_map<int,bool> vis;
        
        for(auto&pair:adjacentPairs){
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
            vis[pair[0]] = true;
            vis[pair[1]] = true;
        }
        
        int start = -1;
        
        for(auto&l:graph)
            if(l.second.size() == 1)
                start = l.first;
        
        vector<int> ans;
        
        while(!vis.empty()){
            
            ans.push_back(start);
            vis.erase(start);
            
            for(int&nxt:graph[start])
                if(vis.find(nxt)!=vis.end())
                    start = nxt;
        }
        
        return ans;
        
    }
};