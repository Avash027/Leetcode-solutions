class Solution {
private:
    vector<vector<int>> ans;
    
    void permute(int i, vector<int>&nums, vector<int> subset={}){
        
        if(i == nums.size()){
            sort(subset.begin() , subset.end());
            if(find(ans.begin(),ans.end(),subset)==ans.end()){
                
                ans.push_back(subset);
            }
            return;
        }
        
        
        permute(i+1,nums,subset);
        subset.push_back(nums[i]);
        permute(i+1,nums,subset);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        permute(0,nums);
        
        return ans;
    }
};