class Solution {
public:
    vector<int> ans;
    
    int binarySearch(const vector<int>&nums , int target){
        int lo = 0 ,hi = (int)nums.size()-1;
        int ind = 0;
        
        while(lo<=hi)
        {
            int mid = (lo+hi)/2;
            
            if(nums[mid]>=target)
            {
                ind = mid;
                hi = mid-1;
            }else lo = mid+1;
        }
        
        return lo;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        ans.assign(2 , -1);
        int n = nums.size();
        if(n == 0) return ans;
        
        ans[0] = binarySearch(nums , target);
        ans[1] = binarySearch(nums , target+1)-1;
        
        
        if(ans[0]<n and nums[ans[0]] == target) return ans;
        else return {-1,-1};
    }
};