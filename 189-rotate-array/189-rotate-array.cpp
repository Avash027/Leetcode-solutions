class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans;
        
        k%=nums.size();
        
        while(k--){
            ans.push_back(nums.back());
            nums.pop_back();
        }
        reverse(begin(ans),end(ans));
        
        nums.insert(begin(nums) , begin(ans),end(ans));
        
        
    }
};