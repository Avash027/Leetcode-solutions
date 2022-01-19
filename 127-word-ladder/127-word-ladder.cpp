class Solution {
private:
 
    unordered_map<string,bool> in; 
    unordered_map<string,int> dis;
  
    
  
    
    void bfs(string src){
       
        queue<string> q;
        q.push(src);
        dis[src] = 1;
        
        while(!q.empty()){
            string v = q.front();
            q.pop();
            in.erase(v);
            int d = dis[v];
            
            for(int i = 0;i<v.size();i++){
                for(char c = 'a';c<='z';c++){
                    char temp = v[i];
                    v[i] = c;
                    
                    if(in[v] and dis.count(v)==0){
                        dis[v] = d+1;
                        q.push(v);
                    }
                    
                    v[i] = temp;
                }
            }
        }
    }
    
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(auto&e:wordList) in[e] = true;
        
        
        bfs(beginWord);
        
        
        
        return dis[endWord];
    }
};