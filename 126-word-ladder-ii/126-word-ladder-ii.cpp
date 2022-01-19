class Solution {
    private:
    vector<vector<string>> ans;
    unordered_map<string,bool> in; 
    unordered_map<string,int> dis;
    unordered_map<string,vector<string>> par;
    
    void findParent(string x , string beginword,vector<string> path){
        
        if(x == beginword){
            path.push_back(beginword);
            ans.push_back(path);
            return;
        }
        
        for(string e:par[x]){
            
            path.push_back(x);
            findParent(e,beginword,path);
            path.pop_back();
        }
    }
  
    void bfs(string src){
       
        queue<string> q;
        q.push(src);
        
        for(auto e: in) dis[e.first] = 1000000;
        
        dis[src] = 1;
        
        
        while(!q.empty()){
            string v = q.front();
            q.pop();
            in.erase(v);
            int d = dis[v];
            string x = v;
            
            for(int i = 0;i<v.size();i++){
                for(char c = 'a';c<='z';c++){
                    char temp = v[i];
                    v[i] = c;
                    
                    if(in[v] and dis[v] > d +1){
                        
                        dis[v] = d+1;
                        q.push(v);
                        par[v].clear();
                        par[v].push_back(x);
                        
                    }else if(in[v] and dis[v] == d+1){
                        par[v].push_back(x);
                    }
                    
                    v[i] = temp;
                }
            }
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for(string&e:wordList) in[e] = true;
        bfs(beginWord);
        
        if(dis[endWord]==1000000) return ans; 
        
        findParent(endWord,beginWord,{});
        
        for(auto&e:ans) reverse(e.begin(),e.end());
        return ans;
    }
};