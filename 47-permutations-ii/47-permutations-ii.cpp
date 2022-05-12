class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(begin(nums),end(nums));
        
        vector<vector<int>> a;
        
        do{
            a.push_back(nums);
        }while(next_permutation(begin(nums),end(nums)));
    
        
        return a;
    
    }
};