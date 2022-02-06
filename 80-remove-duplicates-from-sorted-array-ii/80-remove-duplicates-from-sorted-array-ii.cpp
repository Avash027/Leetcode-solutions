class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 2;
        int ans = 0;
        
        for(int e:nums){
            if(ans<k or e>nums[ans-k]) nums[ans++] = e;
        }
       
        return ans;
    }
};