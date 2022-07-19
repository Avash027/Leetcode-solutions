class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>(1,1));
        
        for(int i =2;i<=numRows;i++)
        {
            vector<int> curRow;
            curRow.push_back(1);
            
            for(int j = 0;j<int(ans[i-2].size()) -1;j++)
            {
                curRow.push_back(ans[i-2][j] + ans[i-2][j+1]);
            }
            curRow.push_back(1);
            
            ans.push_back(curRow);
        }
        return ans;
    
    }
};