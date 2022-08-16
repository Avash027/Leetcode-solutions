class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> narr(n+1 , 0);
        int range = 0;
        int cnt = 0;
        
        for(int i = 0;i<=n;i++){
            int prev = max(i - ranges[i] , 0);
            
            narr[prev] = max(ranges[prev] , i+ ranges[i]);
        }
        
        
        for(int i = 0,mx = 0; i<narr.size() and mx<n;mx = range ){
            cnt++;
            
            while(i<narr.size() and i<=mx){
                range = max(range , narr[i]);
                i++;
            }
            
            if(mx == range) return -1;
            
        }
        
        return cnt;
        
    }
};