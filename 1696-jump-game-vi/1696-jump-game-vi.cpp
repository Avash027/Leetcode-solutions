class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        const int N = nums.size();
        priority_queue<pair<int,int>> pq;
        
        pq.push({nums[0] , 0});
        
        for(int i = 1;i<N;i++){
            
            while(i - pq.top().second>k)
                pq.pop();
            
            nums[i]+= pq.top().first;
            
            pq.push({nums[i]  , i});
        }
        
        return nums.back();
    }
};