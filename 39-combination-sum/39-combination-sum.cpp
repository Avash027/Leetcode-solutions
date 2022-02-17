class Solution {
public:
    
    void generateSum(vector<int> arr ,int i ,int target , vector<int> cur,
                    vector<vector<int>>&ans
                    )
    {
        
        if(target<0) return;
        
        if(target == 0)
        {
            ans.push_back(cur);
            return;
        }
        
        if(i == arr.size()) return;
        
        cur.push_back(arr[i]);
        generateSum(arr , i , target - arr[i] , cur, ans);
        
        cur.pop_back();
        generateSum(arr , i+1 , target , cur,ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        generateSum(candidates , 0 , target , {} , ans);
        return ans;
    }
};