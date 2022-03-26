class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0 , hi = nums.size()-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            
            if(target == nums[mid]) return mid;
            
            if(target>nums[mid]) lo = mid+1;
            else hi = mid-1;
        }
        
        return -1;
    }
};