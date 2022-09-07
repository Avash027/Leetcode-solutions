constexpr long long INF = 1e14;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        const int N = nums.size();
        
        long long prev_ev= nums[0],prev_od = -INF;
        
        
        
        
        for(int i = 1;i<N;i++){
            long long cur_ev = max({1LL*nums[i], prev_od + nums[i],prev_ev});
            long long cur_od = max({prev_od, -nums[i]+prev_ev});
            
            prev_ev = cur_ev;
            prev_od = cur_od;
            
        }
        
        return max(prev_ev , prev_od);
        
        
    }
};