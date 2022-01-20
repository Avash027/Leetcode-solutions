class Solution {
private:
    inline bool check(vector<int>& q , int n , int mx){
        int cnt = 0;
        for(int e:q) cnt+=(e+mx-1)/mx;
        
        return cnt<=n;
    }
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int lo = 1 , hi = *max_element(begin(q),end(q));
        int ans = 0;
        
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(q,n,mid)) ans = mid , hi = mid-1;
            else lo = mid+1;
        }
        
        return ans;
    }
};