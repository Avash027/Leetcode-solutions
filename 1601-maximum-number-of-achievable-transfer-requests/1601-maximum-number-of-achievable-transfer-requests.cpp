class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = (1<<requests.size())-1;
        
        int ans =0;
        
        for (int s=m; s; s=(s-1)&m){
            int submask = s;
            int ind = 0;
            int cnt = __builtin_popcount(s);
            
            vector<int> v(n,0);
            
            while(submask){
                if(submask&1) v[requests[ind][0]]-- , v[requests[ind][1]]++;
                ind++;
                submask>>=1;
            }
            
            bool ok = 1;
            for(int x:v)
                ok&=(x == 0);
            
            if(ok)
                ans = max(ans,cnt);

            
        }
        
        return ans;
    }
};