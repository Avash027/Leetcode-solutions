class Solution {
private:
    bool check(vector<int>&arr , long long k,int h){
        int cnt = 0;
        
        for(int e:arr)
            cnt+=(int)((e+k-1)/k);
        
        return cnt<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long lo = 1 , hi = 1e9+10;
        long long ans = 0;
        
        
        while(lo<=hi){
            long long mid = lo + (hi-lo)/2;    
            
            if(check(piles,mid,h)) ans = mid , hi = mid-1;
            else lo = mid+1;
        
        }
        
        return (int)ans;
    }
};