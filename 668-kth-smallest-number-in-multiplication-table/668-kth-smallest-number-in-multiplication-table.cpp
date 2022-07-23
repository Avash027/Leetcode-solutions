class Solution {
private:
    int count(int n,int m,int val){
        int cnt = 0;
        
        for(int i = 1;i<=n;i++)
            cnt+=min(val/i,m);
        
        return cnt;
    }
public:
    int findKthNumber(int n, int m, int k) {
        
        int lo = 1,hi = m*n+1;
        int ans = 0;
        
        
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;    
            if(count(n,m,mid)>=k) ans = mid , hi = mid-1;
            else lo = mid+1;
        
        }
        
        return ans;
    }
};