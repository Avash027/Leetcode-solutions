class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> ump;
        
        int sum = 0;
        ump[0] = -1;
        int ans = 0;
        int i =0;
        for(int& e:nums){
            sum+=(e?1:-1);
            
            if(ump.find(sum)!=ump.end())
                ans = max(ans , i-ump[sum]);
            else ump[sum] = i;
            
            i++;
        }
        
        return ans;
    }
};