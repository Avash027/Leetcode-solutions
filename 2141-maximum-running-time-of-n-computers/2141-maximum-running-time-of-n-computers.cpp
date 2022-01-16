class Solution {
public:
    long long maxRunTime(int n, vector<int>& b) {
        long long l = 0 , r = accumulate(b.begin(),b.end(),0LL)+1LL;
        long long ans = 0;
        
        while(l<=r){
            long long mid = l + (r-l)/2;//hours per comp
            long long p = 0;
            
            for(int&e:b)
                p+=min(mid , 1LL*e);
            
            if(p>=1LL*mid*n) ans = mid , l = mid+1;
            else r = mid-1;
            
        }
        
        return ans;
        
    }
};