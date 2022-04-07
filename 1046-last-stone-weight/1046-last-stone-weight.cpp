class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        for(int e:stones) pq.push(e);
        
        while(pq.size()>=2){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            
            int mn = min(x,y);
            
            
            
            x-=mn;
            y-=mn;
            
            if(x) pq.push(x);
            if(y) pq.push(y);
        }
        return pq.size()==0?0:pq.top();
    }
};