class Solution {
private:
    static const int N  = 600;
    vector<pair<int , double>> adj[N];
    unordered_map<string,int> sti;
    double res;
    
    
    void dfs(int v , int target , vector<int>& vis , double ans =1){
        vis[v] = true;

        
        if(v == target)
            res = ans;
        
        for(auto to:adj[v])
            if(!vis[to.first])
                dfs(to.first , target , vis , ans*to.second);

    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int timer = 0;
        
        for(int i = 0;i<equations.size();i++){
            string fr = equations[i][0];
            string to = equations[i][1];

            if(sti.count(fr) == 0) sti[fr] = timer++;
            if(sti.count(to) == 0) sti[to] = timer++;
            
            adj[sti[fr]].push_back({sti[to] , values[i]});
            adj[sti[to]].push_back({sti[fr] , double(1)/values[i]});
        }
        
        
        vector<double> ans;
        
        for(auto e:queries){
            
            if(sti.count(e[0]) == 0 or sti.count(e[1]) == 0){
                ans.push_back(-1);
                continue;
            }
            
            vector<int> vis(N , false);
            res = -1;
            dfs(sti[e[0]] , sti[e[1]] , vis);
            
            if(!vis[sti[e[1]]])
                ans.push_back(-1);
            else
                ans.push_back(res);
            }
        
        return ans;
    }
};