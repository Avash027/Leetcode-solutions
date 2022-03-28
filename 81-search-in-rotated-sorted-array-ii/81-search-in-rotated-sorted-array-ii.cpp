class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0 , hi = (int)nums.size()-1;
        
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            
            if(nums[mid] == target)
                return true;
            
            if( (nums[lo] == nums[mid]) and (nums[hi] == nums[mid]) ) {
                ++lo; --hi;
            }
            else if(nums[lo]<=nums[mid]){
                if(target < nums[mid] and target>=nums[lo])
                    hi = mid-1;
                else
                    lo = mid+1;
            }
            else{
                if(target>nums[mid] and target<=nums[hi])
                    lo = mid+1;
                else
                    hi = mid-1;
            }
        
        }
        return false;
    }
};