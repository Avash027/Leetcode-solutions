class Solution {
private:
    vector<vector<int>> ans;
    
    void permute(int i, vector<int>&nums, vector<int> subset={}){
        
        if(i == nums.size()){
            ans.push_back(subset);
            return;
        }
        
        
        permute(i+1,nums,subset);
        subset.push_back(nums[i]);
        permute(i+1,nums,subset);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        permute(0,nums);
        return ans;
    }
};