class Solution {
private:
    bool check(vector<int>&arr , int mx,int m){
        int sum = 0 ,cnt = 1;
        
        for(int e:arr){
            if(sum + e>mx){
                cnt++;
                sum = e;
                if(sum>mx) return false;
            }
            else sum+=e;
        }
        return cnt<=m;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int lo = 0 , hi = 1e9;
        int ans = 0;
        
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(nums,mid,m)) ans = mid , hi = mid-1;
            else lo = mid+1;
        }
        
        return ans;
    }
};