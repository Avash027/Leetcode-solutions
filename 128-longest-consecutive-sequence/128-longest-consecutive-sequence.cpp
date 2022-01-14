class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> count;
        
        for(int&e:nums) count[e]++;
        
        int ans = 0;
        
        for(const int&e:nums){
            if(!count[e]) continue;
            int cnt = 1;
            int i = e-1 , j = e+1;
            
            while(count[i]) count[i] = 0 , cnt++ , i--;
            while(count[j]) count[j] = 0 , cnt++ , j++;
            
            ans = max(ans , cnt);
        }
        
        return ans;
    }
};