class Solution {
private:


int nxt_elem(vector<int>& nums,int k,int mx){
    int lo = k , hi = nums.size()-1;
    int ans = k;
    
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        
        if(nums[mid]>=mx)
            ans = mid , lo = mid+1;
        else 
            hi = mid-1;
    }
    
    return ans;
    
}
    
int prev_elem(vector<int>& nums,int k,int mx){
    int lo = 0 , hi = k;
    int ans = k;
    
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        
        if(nums[mid]>=mx)
            ans = mid , hi = mid-1;
        else 
            lo = mid+1;
    }
    
    return ans;
    
}
    
public:
    int maximumScore(vector<int>& nums, int k) {
        const int N = nums.size();
  
        int ans = nums[k];
        
        for(int i = k+1;i<N;i++){
            nums[i] = min(nums[i] , nums[i-1]);
            ans = max(ans , (i-k+1)*nums[i]);
        }
        
        for(int i = k-1;i>=0;i--){
            nums[i] = min(nums[i] , nums[i+1]);
            ans = max(ans , (k-i+1)*nums[i]);
        }
        
 
        
        for(int i = 1;i<=20000;i++){
            int l = prev_elem(nums,k,i);
            int r = nxt_elem(nums,k,i);
            
            ans = max(ans , (r-l+1)*min(nums[r],nums[l]));
        }
        
        return ans;
    }
};