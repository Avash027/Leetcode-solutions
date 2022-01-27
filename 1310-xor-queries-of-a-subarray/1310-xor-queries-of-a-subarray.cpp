class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        
        for(int i = 1;i<arr.size();i++)
            arr[i]^=arr[i-1];
        
        int ind = 0;
        for(auto e:queries){
            ans[ind++] = arr[e[1]]^(e[0]>0?arr[e[0]-1]:0);
        }
        return ans;
    }
};