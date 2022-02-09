class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> pres;
        
        int ans = 0;
        
        for(int e:nums) pres[e]++;
        
        for(auto e:pres){
            if(k == 0 and e.second>1){
                ans++;
            }else if(k!=0 and pres.find(e.first+k)!=pres.end()){
                ans++;
            }
        }
        
        return ans;
        
    }
};