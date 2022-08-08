class Solution {
private:
    inline int sum(vector<int>&pre , int l , int r){
        return  pre[r] - (l == 0?0:pre[l-1]);
    }
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();
        
        for(int i  =1;i<N;i++)
            nums[i]+=nums[i-1];
        
        
        vector<pair<int,int>> suf(N+1 , {-1,-1});
        
        for(int i = N-k;i>=0;i--){
            int cur_sum = sum(nums , i , i+k-1);
            suf[i] = max(make_pair(cur_sum ,-i) , suf[i+1]);
        }
        
        
        pair<int,int> pre = {sum(nums , 0 , k-1) , 0};
        int ans = -1;
        vector<int> ind(3 , 0);
        
        for(int i = k;i<N;i++){
            if(suf[i+k].second == -1) break;
            int cur_sum = sum(nums,i , i+k-1);
            pre = max(pre , make_pair(sum(nums, i-k , i-1) , -(i-k)));
            
            if(ans < pre.first + cur_sum + suf[i+k].first){
                ans = pre.first + cur_sum + suf[i+k].first;
                ind[0] = -pre.second;
                ind[1] = i;
                ind[2] = -suf[i+k].second;
            }
            
            
            
        }
        
        return ind;
        
    }
};