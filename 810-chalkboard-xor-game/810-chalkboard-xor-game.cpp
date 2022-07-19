class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int xr = 0;
        int cnt = 0;
        for(int&e:nums)
            xr^=e;
        
        return xr == 0 or nums.size()%2 == 0;
        
    }
};