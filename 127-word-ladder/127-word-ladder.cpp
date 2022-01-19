class Solution {
private:
    unordered_map<string,vector<string>> adj;
   
    unordered_map<string,int> dis;
  
    
    void make_graph(string&cur , string&s){
        
            if(s.size()!=cur.size() or s==cur) return;
            
            int cnt = 0;
            
            for(int i = 0;i<s.size();i++) cnt+=(s[i]!=cur[i]);
            if(cnt!=1) return;
        
            adj[s].push_back(cur);
            adj[cur].push_back(s);
        
    }
    
    void bfs(string src){
       
        queue<string> q;
        q.push(src);
        dis[src] = 1;
        
        while(!q.empty()){
            string v = q.front();
            q.pop();
            
            for(string&u:adj[v]){
                if(dis.count(u)!=0) continue;
                dis[u] = dis[v]+1;
                q.push(u);
            }
        }
    }
    
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        
        for(int i = 0;i<wordList.size();i++)
            for(int j = i+1;j<wordList.size();j++){
                make_graph(wordList[i],wordList[j]);
            }
        
        bfs(beginWord);
        
        // for(string e:wordList){
        //     cout<<e<<" "<<dis[e]<<"\n";    
        // }
        
        
        return dis[endWord];
    }
};