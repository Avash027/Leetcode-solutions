class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        
        for(auto&e:accounts)
            ans = max(ans , accumulate(begin(e),end(e) , 0));
        
        return ans;
    }
};