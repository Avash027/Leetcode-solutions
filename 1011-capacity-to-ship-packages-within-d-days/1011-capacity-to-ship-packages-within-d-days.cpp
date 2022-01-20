class Solution {
private:
    bool check(vector<int>&w,int wt,int days){
        int sum = 0 , cnt = 1;
        
        for(int& e:w){
            if(sum + e>wt){
                cnt++;
                sum =e;
                if(sum>wt) return false;
            }else sum+=e;
        
           
        }
        
        return cnt<=days;
        
    }
public:
    int shipWithinDays(vector<int>& w, int days) {
        int lo = 0 , hi = 5 * 1e7;
        int ans = 0;
        
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            
            if(check(w,mid,days)) ans = mid , hi = mid-1;
            else lo = mid+1;
        }
        
        return ans;
    }
};